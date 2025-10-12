#pragma once
#include <optional>

/**
 * @class Cell
 * @brief Represents one cell in the board and manages its state
 *
 */
class Cell {
public:

    int cellID; ///< Ranging from 1-81
    int rightValue; ///< Ranging from 1-9
    std::optional<int> occupyingValue;
    bool isSelected = false;    ///< If is selected ( for possible number placement)
    bool isHighlighted = false; ///< If is highlighted as a part of selected row/column

    explicit Cell(const int id, const int correct, const std::optional<int> written = std::nullopt) : cellID(id), rightValue(correct), occupyingValue(written) {}

    [[nodiscard]] bool isFilled() const noexcept { return occupyingValue.has_value(); }

};