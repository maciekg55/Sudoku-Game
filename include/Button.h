#pragma once
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include "Board.h"

class Button {
public:
    sf::FloatRect hitbox;
    ButtonActions buttonAction;

    explicit Button(const ButtonActions action, const sf::FloatRect& area) : buttonAction(action), hitbox(area) {}

    bool contains(const sf::Vector2f pos) const {
        return hitbox.contains(pos);
    }

    static void performAction(const ButtonActions& action, Board& board, Cell* selectedCell);


};