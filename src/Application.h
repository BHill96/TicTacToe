#pragma once

#include "interfaces/IUI.h"

#include <memory>

class Application {
    private:
        std::unique_ptr<IUI> ui;
        
    public:
        Application(std::unique_ptr<IUI>);
        void Run();
};