#pragma once

enum BoardState {
    InProgress = 0,
    Draw = 1,
    Winner = 2
};

class IBoard {
    public:
        virtual BoardState CheckState() = 0;
};