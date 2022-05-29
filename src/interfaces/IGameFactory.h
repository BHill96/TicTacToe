#pragma once

#include "structures/GameSettings.cpp"
#include "interfaces/ITicTacToeGame.h"

 #include <memory>

class IGameFactory {
    public:
        virtual ~IGameFactory() = default;
        virtual std::unique_ptr<ITicTacToeGame> CreateGame(GameSettings) = 0;
};