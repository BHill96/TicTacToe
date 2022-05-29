#pragma once

#include "gmock/gmock.h"
#include "interfaces/IGameFactory.h"

class MockGameFactory : public IGameFactory {
    public:
        MOCK_METHOD(std::unique_ptr<ITicTacToeGame>, CreateGame, (GameSettings), (override));
};