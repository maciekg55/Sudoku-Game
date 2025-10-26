#pragma once
#include "Enums.h"
#include <iostream>

/**
 * @class Game
 * @brief Represents the overall game program and manages board, time, score etc.
 *
 */
class Game {
public:
    size_t score;
    size_t numberOfErrors;
    DifficultyLevel difficultyLevel;
    double time;
    std::string saveName;

    explicit Game(const size_t s, const size_t errors, const DifficultyLevel level, const double t, const std::string name) : score(s), numberOfErrors(errors), difficultyLevel(level), time(t), saveName(name) {}

};