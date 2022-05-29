#pragma once

#include "structures/GameResults.cpp"

class ITicTacToeGame {
    public:
        virtual ~ITicTacToeGame() = default;
        virtual void PlayGame() = 0;
        virtual GameResults GetResults() = 0;
};