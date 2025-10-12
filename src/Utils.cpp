#include "Utils.h"

std::pair<int, int> calculateCellsPosition(const Cell& cell){
    int column = ((cell.cellID-1)%9);
    int row = (cell.cellID-1)/9;


    return {column, row};
}
