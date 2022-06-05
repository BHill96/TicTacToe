#pragma once

#include "gmock/gmock.h"
#include "interfaces/IPlayer.h"

class MockPlayer : public IPlayer {
    public:
        MOCK_METHOD(void, Turn, (std::shared_ptr<IBoard>), (override));
};