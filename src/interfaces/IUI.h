#pragma once

#include "structures/GameSettings.cpp"
#include "structures/GameStatus.cpp"
#include "structures/Move.cpp"

class IUI {
    public:
        virtual ~IUI() = default;
        virtual void SetUp() = 0;
        virtual void CheckWindowForChanges() = 0;
        virtual void DrawDemoWindow() = 0;
        virtual bool WindowOpen() = 0;
        virtual GameSettings DisplayGameOptions() = 0;
        virtual void DisplayGameResults(GameStatus) = 0;
        virtual void Render() = 0;
        virtual void Cleanup() = 0;
        virtual std::unique_ptr<Move> DisplayInteractiveBoard(std::shared_ptr<IBoard>) = 0;
};