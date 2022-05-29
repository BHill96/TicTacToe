#pragma once

#include "interfaces/IGameFactory.h"

class GameFactory : public IGameFactory {
    private:

    public:
        GameFactory();
        std::unique_ptr<ITicTacToeGame> CreateGame(GameSettings) override;
};