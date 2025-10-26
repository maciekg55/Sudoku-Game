#pragma once
#include <Board.h>

class DataManager {
public:
    static bool saveBoardToFile(const Board& board, const std::string& path);
    static bool loadBoardFromFile( Board& board, const std::string& path);
    static bool saveChange(const Cell* cell, const std::string& path, const std::optional<int>& lastValue);
    static bool loadChanges(Board& board, const std::string& path);
    static bool clearSaveFiles(const std::string& boardPath, const std::string& changesPath);
};