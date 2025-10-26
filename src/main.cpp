#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sys/_select.h>

#include "Cell.h"
#include "Board.h"
#include "DataManager.h"
#include "InputPanel.h"
#include "Utils.h"
#include "Enums.h"


int main()
{

    /// Window has fixed size reserved for 60x60 blocks in 15x11 format
    auto window = sf::RenderWindow(sf::VideoMode({1200u, 660u}), "Sudoku Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(144);

    Board board;
    board.setPosition({60.f, 60.f});

    Cell* selectedCell = nullptr;
    std::optional<int> lastCellValue = -1;

    const std::vector<Cell> cells = board.cells;

    board.initialize();

    Game currentGame(1, 3, DifficultyLevel::Easy, 11.0, "Run 1");

    //Options Pallet (Next to board)
    InputPanel inputPanel(currentGame);;
    inputPanel.setPosition({660.f, 90.f});  //Make Input Larger Bigger (y-wise)


    constexpr sf::Color backgroundColor(235, 237, 239);

    std::string dynamicSavePath = "/Users/maciekgajdzinski/Documents/Projects/Sudoku-Game/data/dynamic_save_2025.json";


    /// Main Program Loop
    while (window.isOpen())
    {
        ///< Events Handling
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()){window.close();} ///< Exit Game

            ///< Mouse Button is Pressed
            else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                sf::Vector2f mousePos = sf::Vector2f(mouseButtonPressed->position);
                //std::cout<<mouseButtonPressed->position.x<<" "<<mouseButtonPressed->position.y<<'\n';

                ///< Check if Mouse Button was pressed inside the Board Area
                if (board.contains(mousePos)) {


                    for (auto& c : board.cells) c.isHighlighted = false;    ///< Reset All Highlights
                    if (selectedCell) selectedCell->isSelected = false;

                    selectedCell = &board.getCellIDFromClick(sf::Vector2f(mouseButtonPressed->position));
                    std::cout<<selectedCell -> cellID<<'\n';
                    lastCellValue = selectedCell->occupyingValue;

                    selectedCell->isSelected = true;
                    auto [column, row] = calculateCellsPosition(*selectedCell);

                    ///< Highlight Row and Column of Selected Cell
                    for (auto& c : board.cells) {
                        auto [cCol, cRow] = calculateCellsPosition(c);
                        if ((cCol == column || cRow == row) && c.cellID != selectedCell->cellID)
                            c.isHighlighted = true;
                    }

                }

                else if (inputPanel.contains(mousePos)) {
                    inputPanel.handleClick({mousePos.x-660, mousePos.y- 90}, board, selectedCell);    ///< we subtract the values of input panel position because the mouse position is relative to the whole window
                }

                else {
                    for (auto& c : board.cells) c.isHighlighted = false;    ///< Reset All Highlights
                    if (selectedCell) selectedCell->isSelected = false;
                }
            }

            ///< Keyboard Button is Pressed
            else if (const auto* keyboardButtonPressed = event -> getIf<sf::Event::KeyPressed>()) {

                ///< Placing Numbers into Cells
                if (selectedCell != nullptr) {
                    switch (keyboardButtonPressed->scancode) {
                        case sf::Keyboard::Scan::Num1:
                        case sf::Keyboard::Scan::Numpad1:
                            selectedCell->occupyingValue = 1;
                            DataManager::saveChange(selectedCell, dynamicSavePath, lastCellValue);
                            lastCellValue = selectedCell->occupyingValue;
                            break;
                        case sf::Keyboard::Scan::Num2:
                        case sf::Keyboard::Scan::Numpad2:
                            selectedCell->occupyingValue = 2;
                            DataManager::saveChange(selectedCell, dynamicSavePath, lastCellValue);
                            lastCellValue = selectedCell->occupyingValue;
                            break;
                        case sf::Keyboard::Scan::Num3:
                        case sf::Keyboard::Scan::Numpad3:
                            selectedCell->occupyingValue = 3;
                            DataManager::saveChange(selectedCell, dynamicSavePath, lastCellValue);
                            lastCellValue = selectedCell->occupyingValue;
                            break;
                        case sf::Keyboard::Scan::Num4:
                        case sf::Keyboard::Scan::Numpad4:
                            selectedCell->occupyingValue = 4;
                            DataManager::saveChange(selectedCell, dynamicSavePath, lastCellValue);
                            lastCellValue = selectedCell->occupyingValue;
                            break;
                        case sf::Keyboard::Scan::Num5:
                        case sf::Keyboard::Scan::Numpad5:
                            selectedCell->occupyingValue = 5;
                            DataManager::saveChange(selectedCell, dynamicSavePath, lastCellValue);
                            lastCellValue = selectedCell->occupyingValue;
                            break;
                        case sf::Keyboard::Scan::Num6:
                        case sf::Keyboard::Scan::Numpad6:
                            selectedCell->occupyingValue = 6;
                            DataManager::saveChange(selectedCell, dynamicSavePath, lastCellValue);
                            lastCellValue = selectedCell->occupyingValue;
                            break;
                        case sf::Keyboard::Scan::Num7:
                        case sf::Keyboard::Scan::Numpad7:
                            selectedCell->occupyingValue = 7;
                            DataManager::saveChange(selectedCell, dynamicSavePath, lastCellValue);
                            lastCellValue = selectedCell->occupyingValue;
                            break;
                        case sf::Keyboard::Scan::Num8:
                        case sf::Keyboard::Scan::Numpad8:
                            selectedCell->occupyingValue = 8;
                            DataManager::saveChange(selectedCell, dynamicSavePath, lastCellValue);
                            lastCellValue = selectedCell->occupyingValue;
                            break;
                        case sf::Keyboard::Scan::Num9:
                        case sf::Keyboard::Scan::Numpad9:
                            selectedCell->occupyingValue = 9;
                            DataManager::saveChange(selectedCell, dynamicSavePath, lastCellValue);
                            lastCellValue = selectedCell->occupyingValue;
                            break;
                        case sf::Keyboard::Scan::Backspace:
                        case sf::Keyboard::Scan::Delete:
                            selectedCell->occupyingValue.reset();
                            break;
                        default:
                            std::cout << "Only numbers" << std::endl;
                            break;
                    }
                }

            }

        }

        window.clear(backgroundColor);

        window.draw(board); ///< Drawing Board
        window.draw(inputPanel); ///< Drawing Input Panel

        window.display();
    }
}
