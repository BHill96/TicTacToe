#pragma once

#include "interfaces/ITicTacToeGame.h"
#include "structures/GameSettings.cpp"

class TicTacToeGame : public ITicTacToeGame {
    private:
        std::shared_ptr<IPlayerQueue> playerQueue;
        std::shared_ptr<IBoard> board;
        BoardState boardState;
        
    public:
        TicTacToeGame(std::shared_ptr<GameSettings>);
        ~TicTacToeGame() = default;
        GameStatus PlayGame() override;
};