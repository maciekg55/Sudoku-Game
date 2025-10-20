#include "../include/Board.h"

#include "../SudokuGenerator.h"

///< Constructor
Board::Board() {
    createGrid();
}

void Board::createGrid(){
    cells.clear();
    cells.reserve(81);
    for (int i = 0; i<81; i++) {
        cells.emplace_back(i+1, 2);
    }
}

bool Board::contains(const sf::Vector2f& mousePos) const {
    const sf::Vector2f pos = getPosition();
    const sf::FloatRect bounds({pos, boardSize});
    if (bounds.contains(mousePos)){ return true;}
    return false;
}

Cell& Board::getCellIDFromClick(const sf::Vector2f& mousePos) {
    int row = mousePos.y/60;
    int column = mousePos.x/60;

    int index = (row-1)*9 + column-1;
    Cell& selected = cells[index];
    return selected;
}

void Board::initialize() {
    SudokuGenerator generator;
    std::array<int, 81> newCells{};
    generator.emplaceNumber(newCells, 0);
    for (int i = 0; i<81; i++) {
        cells[i].rightValue = newCells[i];
    }
}


void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        const sf::Font normalFont("assets/helvetica-light.ttf");
        const sf::Font boldFont("assets/helvetica-bold.ttf");
        constexpr sf::Color highlightColor(226, 235, 243);
        constexpr sf::Color selectedColor(187, 222, 251);
        constexpr sf::Color thickOutlineColor(52, 72, 97);
        constexpr sf::Color thinOutlineColor(206, 214, 224);

        constexpr sf::Color gray(222, 219, 213);

        states.transform *= getTransform();

        for (const auto& c : cells) {

            sf::RectangleShape cell({60.f, 60.f});
            auto [col, row] = calculateCellsPosition(c);
            cell.setPosition({col * 60.f, row * 60.f});
            if (c.isHighlighted){ cell.setFillColor(highlightColor); }
            else if (c.isSelected) {cell.setFillColor(selectedColor); }
            else{ cell.setFillColor(sf::Color::White); }

            target.draw(cell, states);

            sf::Text cellIDText(normalFont, std::to_string(c.cellID));
            cellIDText.setPosition({col * 60.f + 45.f, row * 60.f + 45.f});
            cellIDText.setFillColor(gray);
            cellIDText.setCharacterSize(10);

            target.draw(cellIDText, states);

            sf::Text rightCellValue(normalFont, std::to_string(c.rightValue));
            rightCellValue.setPosition({col * 60.f + static_cast<float>(22), row * 60.f + 10.f});
            rightCellValue.setFillColor(sf::Color::Black);
            rightCellValue.setCharacterSize(35);

            target.draw(rightCellValue, states);

            if (c.occupyingValue != std::nullopt) {
                sf::Text cellOccupyingValue(c.isSelected ? boldFont : normalFont, std::to_string(c.occupyingValue.value()));
                cellOccupyingValue.setPosition({
                    c.isSelected ? (col * 60.f + static_cast<float>(22)) : (col * 60.f + static_cast<float>(22.5)),
                    (row * 60.f + 10.f)
                });
                cellOccupyingValue.setFillColor(sf::Color::Black);
                cellOccupyingValue.setCharacterSize(c.isSelected ? 35 : 30);

                target.draw(cellOccupyingValue, states);
            }


        }

        sf::RectangleShape line;
        float thin = 2.5f;
        float thick = 4.f;

        ///< Vertical Lines - thin
        for (int i = 0; i<10; i++) {
            line.setSize({i % 3 == 0 ? 0 : thin, 540.f});   ///< only draw thin ones because we will be adding thick vertical lines later.
            line.setPosition({i * 60.f, 0.f});
            line.setFillColor(thinOutlineColor);
            target.draw(line, states);
        }

        ///< Horizontal Lines
        for (int i = 0; i<10; i++) {
            line.setSize({540.f, i % 3 == 0 ? thick : thin});
            line.setPosition({0.f, i * 60.f});
            line.setFillColor(i%3 == 0 ? thickOutlineColor : thinOutlineColor);
            target.draw(line, states);
        }

        ///< Vertical Lines - thick
        for (int i = 0; i<4; i++) {
            line.setSize({thick, (i == 3 ? 544.f : 540.f)});  ///< draw thick vertical lines because they need to overlay horizonal lines. / The last (i=3) line has to be longer to to cover empty spot.
            line.setPosition({i * 180.f, 0.f});
            line.setFillColor(thickOutlineColor);
            target.draw(line, states);
        }

    }