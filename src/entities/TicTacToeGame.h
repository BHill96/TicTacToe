#pragma once

#include "interfaces/ITicTacToeGame.h"

class TicTacToeGame : public ITicTacToeGame {
    private:
        
    public:
        TicTacToeGame();
        void CheckGameState() override;
        void PlayGame() override;
        GameResults GetResults() override;
};