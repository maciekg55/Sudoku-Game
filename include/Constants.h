#pragma once
#include <SFML/Graphics.hpp>

namespace Constants {
    inline const sf::Font normalFont("assets/helvetica-light.ttf");
    inline const sf::Font boldFont("assets/helvetica-bold.ttf");

    inline constexpr sf::Color highlightColor(226, 235, 243);
    inline constexpr sf::Color selectedColor(187, 222, 251);
    inline constexpr sf::Color thickOutlineColor(52, 72, 97);
    inline constexpr sf::Color thinOutlineColor(206, 214, 224);
    inline constexpr sf::Color gray(230, 230, 230);
}