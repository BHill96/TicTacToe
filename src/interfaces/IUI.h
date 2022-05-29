#pragma once

#include "structures/GameSettings.cpp"
#include "structures/GameResults.cpp"

class IUI {
    public:
        virtual ~IUI() = default;
        virtual GameSettings DisplayGameOptions() = 0;
        virtual void DisplayGameResults(GameResults) = 0;
};