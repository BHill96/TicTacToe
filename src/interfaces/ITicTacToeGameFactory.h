#pragma once

#include "structures/GameSettings.cpp"
#include "interfaces/ITicTacToeGame.h"

 #include <memory>

class ITicTacToeGameFactory {
    public:
        virtual ~ITicTacToeGameFactory() = default;
        virtual std::unique_ptr<ITicTacToeGame> CreateGame(GameSettings) = 0;
};