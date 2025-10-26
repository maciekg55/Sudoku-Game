#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Cell.h"
#include "Utils.h"
#include "SudokuGenerator.h"
#include "Constants.h"


/**
 * @class Board
 * @brief Represents and manages board, consisting of individual cells.
 *
 * Responsible for all cell interactions.
 *
 */
class Board: public sf::Drawable, public sf::Transformable{
public:
    std::vector<Cell> cells; ///< Always consisting of 81 objects
    Board();

    bool contains(const sf::Vector2f& mousePos) const;
    Cell& getCellIDFromClick(const sf::Vector2f& mousePos);
    void initialize();
private:
    sf::Vector2f boardSize{540.f, 540.f};
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void createGrid();
};