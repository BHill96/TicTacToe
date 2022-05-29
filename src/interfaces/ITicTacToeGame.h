#pragma once

#include "structures/GameResults.cpp"

class ITicTacToeGame {
    public:
        virtual ~ITicTacToeGame() = default;
        virtual void CheckGameState() = 0;
        virtual void PlayGame() = 0;
        virtual GameResults GetResults() = 0;
};