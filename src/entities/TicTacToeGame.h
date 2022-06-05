#pragma once

#include "interfaces/ITicTacToeGame.h"
#include "structures/GameSettings.cpp"

class TicTacToeGame : public ITicTacToeGame {
    private:
        std::shared_ptr<IPlayerQueue> playerQueue;
        std::shared_ptr<IBoard> board;
        
    public:
        TicTacToeGame(std::shared_ptr<GameSettings>);
        ~TicTacToeGame() = default;
        GameResults PlayGame() override;
};