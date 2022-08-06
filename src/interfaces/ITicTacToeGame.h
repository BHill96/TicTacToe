#pragma once

#include "structures/GameStatus.cpp"

class ITicTacToeGame {
    public:
        virtual ~ITicTacToeGame() = default;
        virtual GameStatus PlayGame() = 0;
};