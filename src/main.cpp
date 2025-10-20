#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"
#include "Board.h"
#include "Utils.h"


int main()
{

    /// Window has fixed size reserved for 60x60 blocks in 15x11 format
    auto window = sf::RenderWindow(sf::VideoMode({1200u, 660u}), "Sudoku Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(144);

    Board board;
    board.setPosition({60.f, 60.f});

    Cell* selectedCell = nullptr;

    const std::vector<Cell> cells = board.cells;

    board.initialize();

    constexpr sf::Color backgroundColor(235, 237, 239);

    /// Main Program Loop
    while (window.isOpen())
    {
        ///< Events Handling
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()){window.close();} ///< Exit Game

            ///< Mouse Button is Pressed
            else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {

                //std::cout<<mouseButtonPressed->position.x<<" "<<mouseButtonPressed->position.y<<'\n';

                ///< Check if Mouse Button was pressed inside the Board Area
                if (board.contains(sf::Vector2f(mouseButtonPressed->position))) {


                    for (auto& c : board.cells) c.isHighlighted = false;    ///< Reset All Highlights
                    if (selectedCell) selectedCell->isSelected = false;

                    selectedCell = &board.getCellIDFromClick(sf::Vector2f(mouseButtonPressed->position));
                    std::cout<<selectedCell -> cellID<<'\n';

                    selectedCell->isSelected = true;
                    auto [column, row] = calculateCellsPosition(*selectedCell);

                    ///< Highlight Row and Column of Selected Cell
                    for (auto& c : board.cells) {
                        auto [cCol, cRow] = calculateCellsPosition(c);
                        if ((cCol == column || cRow == row) && c.cellID != selectedCell->cellID)
                            c.isHighlighted = true;
                    }

                }
                else {
                    for (auto& c : board.cells) c.isHighlighted = false;    ///< Reset All Highlights
                    if (selectedCell) selectedCell->isSelected = false;
                }
            }

            ///< Keyboard Button is Pressed
            else if (const auto* keyboardButtonPressed = event -> getIf<sf::Event::KeyPressed>()) {
                // std::cout<<"Keyboard Button has been pressed";
                // if (keyboardButtonPressed->code in  && selectedCell != nullptr) {
                //     selectedCell->occupyingValue = 1;
                //     std::cout << sf::Keyboard::getDescription;
                // }

                ///< Placing Numbers into Cells
                if (selectedCell != nullptr) {
                    switch (keyboardButtonPressed->scancode) {
                        case sf::Keyboard::Scan::Num1:
                        case sf::Keyboard::Scan::Numpad1:
                            selectedCell->occupyingValue = 1;
                            break;
                        case sf::Keyboard::Scan::Num2:
                        case sf::Keyboard::Scan::Numpad2:
                            selectedCell->occupyingValue = 2;
                            break;
                        case sf::Keyboard::Scan::Num3:
                        case sf::Keyboard::Scan::Numpad3:
                            selectedCell->occupyingValue = 3;
                            break;
                        case sf::Keyboard::Scan::Num4:
                        case sf::Keyboard::Scan::Numpad4:
                            selectedCell->occupyingValue = 4;
                            break;
                        case sf::Keyboard::Scan::Num5:
                        case sf::Keyboard::Scan::Numpad5:
                            selectedCell->occupyingValue = 5;
                            break;
                        case sf::Keyboard::Scan::Num6:
                        case sf::Keyboard::Scan::Numpad6:
                            selectedCell->occupyingValue = 6;
                            break;
                        case sf::Keyboard::Scan::Num7:
                        case sf::Keyboard::Scan::Numpad7:
                            selectedCell->occupyingValue = 7;
                            break;
                        case sf::Keyboard::Scan::Num8:
                        case sf::Keyboard::Scan::Numpad8:
                            selectedCell->occupyingValue = 8;
                            break;
                        case sf::Keyboard::Scan::Num9:
                        case sf::Keyboard::Scan::Numpad9:
                            selectedCell->occupyingValue = 9;
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

        window.display();
    }
}
