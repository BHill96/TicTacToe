#pragma once

#include "gmock/gmock.h"
#include "interfaces/IGameFactory.h"

class MockGameFactory : public IGameFactory {
    public:
        MOCK_METHOD(void, CreateGame, (GameSettings), (override));
};