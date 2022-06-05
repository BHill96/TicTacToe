#pragma once

#include "gmock/gmock.h"
#include "interfaces/ITicTacToeGameFactory.h"

class MockTicTacToeGameFactory : public ITicTacToeGameFactory {
    public:
        MOCK_METHOD(std::unique_ptr<ITicTacToeGame>, CreateGame, (GameSettings), (override));
};