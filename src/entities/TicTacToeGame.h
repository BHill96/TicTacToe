#pragma once

#include "interfaces/ITicTacToeGame.h"
#include "structures/GameSettings.cpp"

class TicTacToeGame : public ITicTacToeGame {
    private:
        
    public:
        TicTacToeGame(GameSettings);
        void PlayGame() override;
        GameResults GetResults() override;
};