#pragma once

class ITicTacToeGame {
    public:
        virtual ~ITicTacToeGame() = default;
        virtual void CheckGameState() = 0;
        virtual void PlayGame() = 0;
};