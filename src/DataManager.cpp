#include "DataManager.h"
#include  <json.hpp>
#include <fstream>
#include <iostream>

using nlohmann::json;

bool DataManager::clearSaveFiles(const std::string &boardPath, const std::string &changesPath) {
    // Write minimal empty board file
    {
        std::ofstream boardFile(boardPath);
        if (!boardFile.is_open()) return false;

        boardFile << "{ \"cells\": [] }"; // valid JSON structure
    }

    // Write minimal empty change history
    {
        std::ofstream changeFile(changesPath);
        if (!changeFile.is_open()) return false;

        changeFile << "{ \"changes\": [] }";
    }

    return true;
}


bool DataManager::saveBoardToFile(const Board &board, const std::string &path) {
    json j;
    j["cells"] = json::array();

    for (const auto& cell : board.cells) {
        j["cells"].push_back({
        {"id", cell.cellID},
        {"rightValue", cell.rightValue},
        {"occupyingValue", cell.occupyingValue.value_or(-1)},
        });
    }

    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr <<"Failed to open: "<<path<<"\n";
        return false;
    }

    file<<j.dump(3);
    return false;
}


bool DataManager::loadBoardFromFile( Board &board, const std::string &path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr<<"Failed to open: "<<path<<"\n";
        return false;
    }
    json j;
    try {
        file>>j;
    } catch (const std::exception& e) {
        std::cerr<<"JSON parsing error: "<<e.what()<<"\n";
        return false;
    }

    if (!j.contains("cells") || !j["cells"].is_array()) {
        std::cerr<<"Invalid JSON format\n";
        return false;
    }

    try {
        for (const auto& cellData: j["cells"]) {
            int id = cellData.at("id").get<int>();
            auto& cell = board.cells.at(id - 1);

            cell.rightValue = cellData.at("rightValue").get<int>();

            int val = cellData.at("occupyingValue").get<int>();
            if (val == -1)
                cell.occupyingValue.reset();
            else
                cell.occupyingValue = val;
        }
    } catch (const std::exception& e) {
        std::cerr<<"JSON parsing error: "<<e.what()<<"\n";
        return false;
    }
    return true;
}

bool DataManager::saveChange(const Cell* cell, const std::string& path, const std::optional<int>& lastValue) {
    json j;

    std::ifstream file(path);
    if (file.is_open()) {
        try {
            file >> j;
        } catch (...) {
            j = json::object();
        }
    }

    if (!j.contains("changes") || !j["changes"].is_array()) {
        j["changes"] = json::array();
    }

    j["changes"].push_back({
    {"id", cell->cellID},
    {"rightValue", cell->rightValue},
    {"occupyingValue", cell->occupyingValue.value_or(-1)},
        {"lastValue", lastValue.value_or(-1)}
    });

    std::ofstream out(path);
    if (!out.is_open()) {
        std::cerr << "Failed to open: " << path << "\n";
        return false;
    }

    out<<j.dump(3);
    return true;
}

bool DataManager::loadChanges(Board& board, const std::string& path) {
    json j;

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open: " << path << "\n";
        return false;
    }

    try {
        file >> j;
    } catch (...) {
        std::cerr << "Error reading JSON file\n";
        return false;
    }

    auto& arr = j["changes"];
    if (!arr.is_array() || arr.empty()) {
        std::cout<<"No changes to undo\n";
        return false;
    }

    json last = arr.back();
    int id = last["id"].get<int>();
    int oldValue = last["lastValue"].get<int>();

    auto& cell = board.cells.at(id - 1);
    if (oldValue == -1) {
        cell.occupyingValue = std::nullopt;
    }else {
        cell.occupyingValue = oldValue;
    }

    arr.erase(arr.end() -1);

    std::ofstream out(path);
    out<<j.dump(3);

    return true;
}

