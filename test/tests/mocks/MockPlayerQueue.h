#pragma once

#include "gmock/gmock.h"
#include "interfaces/IPlayerQueue.h"

class MockPlayerQueue : public IPlayerQueue {
    public:
        MOCK_METHOD(std::shared_ptr<IPlayer>, Front, (), (override));
        MOCK_METHOD(void, Next, (), (override));
};