#pragma once

#include "interfaces/IPlayer.h"
#include "interfaces/IUI.h"
#include <string>

class Human : public IPlayer {
    private:
        std::string name;
        char symbol;
        std::shared_ptr<IUI> ui;

    public:
        Human(std::string,char,std::shared_ptr<IUI>);
        bool Turn(std::shared_ptr<IBoard>) override;
};