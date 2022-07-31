#pragma once

#include "interfaces/ITicTacToeGameFactory.h"

class TicTacToeGameFactory : public ITicTacToeGameFactory {
    public:
        ~TicTacToeGameFactory() = default;
        std::unique_ptr<ITicTacToeGame> CreateGame(GameSettings) override;
};