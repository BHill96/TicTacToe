#pragma once

#include "interfaces/IBoard.h"
#include <vector>

class TicTacToeBoard : public IBoard {
    private:
        char emptyChar = '#';
        std::vector<std::vector<char>> board;

    public:
        TicTacToeBoard();
        BoardState CheckState() override;
        void Update(std::unique_ptr<Move>) override;
        char Get(int,int) override;
};