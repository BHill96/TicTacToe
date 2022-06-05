#pragma once

#include "structures/GameResults.cpp"

class ITicTacToeGame {
    public:
        virtual ~ITicTacToeGame() = default;
        virtual GameResults PlayGame() = 0;
};