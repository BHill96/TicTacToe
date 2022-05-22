#pragma once

#include "gmock/gmock.h"
#include "interfaces/IUI.h"

class MockUI : public IUI {
    public:
        MOCK_METHOD(void, DisplayGameConfiguration, (), (override));
};