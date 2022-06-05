#pragma once

#include "interfaces/IUI.h"
#include "interfaces/ITicTacToeGameFactory.h"

#include <memory>

class Application {
    private:
        std::unique_ptr<IUI> ui;
        std::unique_ptr<ITicTacToeGameFactory> gameFactory;
        
    public:
        Application(std::unique_ptr<IUI>, std::unique_ptr<ITicTacToeGameFactory>);
        void Run();
};