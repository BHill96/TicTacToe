#pragma once

#include <memory>
#include "structures/Move.cpp"

enum BoardState {
    InProgress = 0,
    Draw = 1,
    Winner = 2
};

class IBoard {
    public:
        virtual BoardState CheckState() = 0;
        virtual void Update(std::unique_ptr<Move>) = 0;
};