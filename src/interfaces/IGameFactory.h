#pragma once

#include "structures/GameSettings.cpp"

class IGameFactory {
    public:
        virtual ~IGameFactory() = default;
        virtual void CreateGame(GameSettings) = 0;
};