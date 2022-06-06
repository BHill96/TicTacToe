#pragma once

enum BoardState {
    InProgress,
    Finished
};

class IBoard {
    public:
        virtual BoardState CheckState() = 0;
};