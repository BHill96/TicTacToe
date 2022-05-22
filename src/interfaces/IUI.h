#pragma once

#include "structures/GameSettings.cpp"

class IUI {
    public:
        virtual ~IUI() = default;
        virtual GameSettings DisplayGameOptions() = 0;
};