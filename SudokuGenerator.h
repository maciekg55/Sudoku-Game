#pragma once
#include <random>
#include <array>
#include "Enums.h"


/**
 * @class SudokuGenerator
 * @brief Generates valid Sudoku puzzle by filling 9x9 grid using backtracking
 * It operates on a 1D array representation of the board (81 integers).
 * The algorithm ensures Sudoku validity by checking rows, columns, and 3x3 blocks.
 *
 */
class SudokuGenerator {
public:
    /**
     *@brief  Recursively fills the Sudoku grid with valid numbers.
     *
     *Uses backtracking and random shuffling to generate a valid Sudoku solution.
     *
     * @param cells Reference to an array of 81 integers representing the Sudoku Board
     * @param index Current index in the grid (0-80) being filled
     * @return true if the grid is successfully filled; false is backtracking is triggered
     */
    bool emplaceNumber(std::array<int, 81> &cells, int index);

private:
    /**
     * @brief Extracts a 9-element subset (row, column or 3x3 bloc) from the grid.
     *
     * Used initially to validate number placement when generating the Sudoku.
     *
     * @param cells Reference to the full 81-element Sudoku array
     * @param rowNumber Row index (0-8)
     * @param colNumber Column index (0-8)
     * @param mode Defines which type of subset to extract (row, column or block)
     * @return std::array<int, 9> The extracted subset of 9 values.
     */
    std::array<int, 9> generateArray(const std::array<int, 81> &cells, int rowNumber, int colNumber, GenerationModes mode);

    /**
     * @brief Checks if a given number already exists in the specified 9-element array
     *
     * @param generatedArray Array of 9 integers (row, column or block)
     * @param number Value to search for
     * @return true if the number exists in the array; otherwise false.
     */
    bool arrayContains(const std::array<int, 9> &generatedArray, const int &number);

};