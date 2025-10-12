#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"
#include "Board.h"
#include "Utils.h"


int main()
{
    /// Window has fixed size reserved for 60x60 blocks in 15x11 format
    auto window = sf::RenderWindow(sf::VideoMode({900u, 660u}), "Sudoku Game", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(144);

    Board board;
    board.setPosition({60.f, 60.f});

    Cell* selectedCell = nullptr;

    const std::vector<Cell> cells = board.cells;

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
            }
        }



        window.clear(backgroundColor);

        window.draw(board); ///< Drawing Board

        window.display();
    }
}
