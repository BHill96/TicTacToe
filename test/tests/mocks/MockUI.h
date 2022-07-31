#pragma once

#include "gmock/gmock.h"
#include "interfaces/IUI.h"

class MockUI : public IUI {
    public:
        MOCK_METHOD(void, SetUp, (), (override));
        MOCK_METHOD(void, CheckWindowForChanges, (), (override));
        MOCK_METHOD(void, DrawDemoWindow, (), (override));
        MOCK_METHOD(bool, WindowOpen, (), (override));
        MOCK_METHOD(GameSettings, DisplayGameOptions, (), (override));
        MOCK_METHOD(void, DisplayGameResults, (GameResults), (override));
        MOCK_METHOD(void, Render, (), (override));
        MOCK_METHOD(void, Cleanup, (), (override));
};