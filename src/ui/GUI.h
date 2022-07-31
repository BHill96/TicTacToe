#pragma once

#include "interfaces/IUI.h"

class GUI : public IUI {
    public:
        ~GUI() = default;
        GameSettings DisplayGameOptions() override;
        void DisplayGameResults(GameResults) override;
};