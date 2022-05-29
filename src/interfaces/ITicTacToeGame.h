#pragma once

class ITicTacToeGame {
    public:
        virtual ~ITicTacToeGame() = default;
        virtual void CheckGameState() = 0;
};