#pragma once

#include "gmock/gmock.h"
#include "interfaces/ITicTacToeGame.h"

class MockTicTacToeGame : public ITicTacToeGame {
    public:
        MOCK_METHOD(void, PlayGame, (), (override));
        MOCK_METHOD(GameResults, GetResults, (), (override));
};