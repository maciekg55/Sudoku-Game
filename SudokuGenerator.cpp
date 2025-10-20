#include "SudokuGenerator.h"

/**
 * @brief Fills the Sudoku board recursively using backtracking and random shuffling.
 */
std::array<int, 9> SudokuGenerator::generateArray(const std::array<int, 81> &cells, const int rowNumber, const int colNumber, const GenerationModes mode) {
    std::array<int, 9> resultArray{};
    switch (mode){
        case rowGeneration:
            for (std::size_t i = 0; i< 9; i++) {
                resultArray[i] = cells[rowNumber*9 + i];
            }
        return resultArray;
        case columnGeneration:
            for (std::size_t i = 0; i< 9; i++) {
                resultArray[i] = cells[colNumber + i*9];
            }
        return resultArray;
        case blockGeneration:
            int i = 0;
        for (std::size_t r = (rowNumber/3 )*3; r < (rowNumber/3 + 1)*3; r++) {
            for (std::size_t c = (colNumber/3)*3; c < (colNumber/3 + 1)*3; c++) {
                std::size_t index = r*9 + c;
                resultArray[i] = cells[index];
                i++;

            }
        }
        return resultArray;
    }
}

/**
 * @brief Checks if a number exists in a given 9-element array.
 */
bool SudokuGenerator::arrayContains(const std::array<int, 9>& generatedArray, const int& number) {
    return std::any_of(generatedArray.begin(), generatedArray.end(),
                       [number](int x) { return x == number; });
}

/**
 * @brief Fills the Sudoku board recursively using backtracking and random shuffling.
 */
bool SudokuGenerator::emplaceNumber(std::array<int, 81> &cells, const int index) {
    if (index == 81) return true; // all cells filled

    std::mt19937 gen(std::random_device{}());
    std::array<int, 9> candidates = {1,2,3,4,5,6,7,8,9};
    std::shuffle(candidates.begin(), candidates.end(), gen);

    int rowNumber = index / 9;
    int colNumber = index % 9;

    std::array<int, 9> columnArray = generateArray(cells, rowNumber, colNumber, columnGeneration);
    std::array<int, 9> rowArray = generateArray(cells, rowNumber, colNumber, rowGeneration);
    std::array<int, 9> blockArray = generateArray(cells, rowNumber, colNumber, blockGeneration);

    for (int num : candidates) {
        if (!arrayContains(columnArray, num) &&
            !arrayContains(rowArray, num) &&
            !arrayContains(blockArray, num)) {

            cells[index] = num;
            if (emplaceNumber(cells, index + 1))
                return true; // success, propagate
            cells[index] = 0; // backtrack
            }
    }
    return false; // trigger backtracking
}

