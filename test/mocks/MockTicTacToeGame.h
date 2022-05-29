#pragma once

#include "gmock/gmock.h"
#include "interfaces/ITicTacToeGame.h"

class MockTicTacToeGame : public ITicTacToeGame {
    public:
        MOCK_METHOD(void, CheckGameState, (), (override));
};