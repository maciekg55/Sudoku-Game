#pragma once
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include "Game.h"
#include "Button.h"

class InputPanel: public sf::Drawable, public sf::Transformable{
public:

    void handleClick(const sf::Vector2f& mousePos, Board& board, Cell* selectedCell) const;
    bool contains(const sf::Vector2f& mousePos) const;
    explicit InputPanel(const Game& g);

private:

    size_t score;
    size_t numberOfErrors;
    DifficultyLevel difficultyLevel;
    double time;
    std::string saveName;
    std::vector<Button> buttons;

    sf::Vector2f panelSize{420.f, 540.f};
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
