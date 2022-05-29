#pragma once

#include "interfaces/ITicTacToeGame.h"

class TicTacToeGame : public ITicTacToeGame {
    private:
        
    public:
        TicTacToeGame();
        void PlayGame() override;
        GameResults GetResults() override;
};