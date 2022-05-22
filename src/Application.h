#pragma once

#include "interfaces/IUI.h"
#include "interfaces/IGameFactory.h"

#include <memory>

class Application {
    private:
        std::unique_ptr<IUI> ui;
        std::unique_ptr<IGameFactory> gameFactory;
        
    public:
        Application(std::unique_ptr<IUI>, std::unique_ptr<IGameFactory>);
        void Run();
};