#pragma once

#include "gmock/gmock.h"
#include "interfaces/IBoard.h"

class MockBoard : public IBoard {
    public:
        MOCK_METHOD(BoardState, CheckState, (), (override));
};