#pragma once

#include "gmock/gmock.h"
#include "interfaces/IBoard.h"

class MockBoard : public IBoard {
    public:
        MOCK_METHOD(BoardState, CheckState, (), (override));
        MOCK_METHOD(void, Update, (std::unique_ptr<Move>), (override));
        MOCK_METHOD(char, Get, (int,int), (override));
};