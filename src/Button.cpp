#include "Button.h"
#include "Board.h"
#include "DataManager.h"
#include <iostream>

void Button::performAction(const ButtonActions& action, Board& board, Cell* selectedCell) {
    std::string path = "/Users/maciekgajdzinski/Documents/Projects/Sudoku-Game/data/save_2025.json";
    std::string dynamicSavePath = "/Users/maciekgajdzinski/Documents/Projects/Sudoku-Game/data/dynamic_save_2025.json";
    bool runNumerical = true;
    if (selectedCell == nullptr){runNumerical = false;}

    switch (action) {
        case erase:
            std::cout<<"Erasing Cells occupying value\n";
            if (runNumerical){selectedCell->occupyingValue = std::nullopt;}

        case saveGame:
            std::cout<<"Saving Game\n";
            DataManager::saveBoardToFile(board, path);
            std::cout<<"Game Saved\n";
            break;

        case loadGame:
            std::cout<<"Loading Game\n";
            DataManager::loadBoardFromFile(board, path);
            std::cout<<"Game Loaded\n";
            break;

        case exitGame:
            std::cout<<"Exiting Game\n";
            break;

        case undo:
            std::cout<<"Undoing last placement\n";
            DataManager::loadChanges(board, dynamicSavePath);
            break;

        case newGame:
            std::cout<<"Clearing Game Files\n";
            DataManager::clearSaveFiles(path, dynamicSavePath);
            break;

        case numeric1:
            std::cout<<"Emplacing 1 into selected Cell\n";
            if (runNumerical){selectedCell->occupyingValue = 1;}
            break;

        case numeric2:
            std::cout<<"Emplacing 2 into selected Cell\n";
            if (runNumerical){selectedCell->occupyingValue = 2;}
            break;

        case numeric3:
            std::cout<<"Emplacing 3 into selected Cell\n";
            if (runNumerical){selectedCell->occupyingValue = 3;}
            break;

        case numeric4:
            std::cout<<"Emplacing 4 into selected Cell\n";
            if (runNumerical){selectedCell->occupyingValue = 4;}
            break;

        case numeric5:
            std::cout<<"Emplacing 5 into selected Cell\n";
            if (runNumerical){selectedCell->occupyingValue = 5;}
            break;

        case numeric6:
            std::cout<<"Emplacing 6 into selected Cell\n";
            if (runNumerical){selectedCell->occupyingValue = 6;}
            break;

        case numeric7:
            std::cout<<"Emplacing 7 into selected Cell\n";
            if (runNumerical){selectedCell->occupyingValue = 7;}
            break;

        case numeric8:
            std::cout<<"Emplacing 8 into selected Cell\n";
            if (runNumerical){selectedCell->occupyingValue = 8;}
            break;

        case numeric9:
            std::cout<<"Emplacing 9 into selected Cell\n";
            if (runNumerical){selectedCell->occupyingValue = 9;}
            break;

        default:
            std::cout<<"Button Pressed\n";
            break;

    }
}
