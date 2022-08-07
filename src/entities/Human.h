#pragma once

#include "interfaces/IPlayer.h"
#include "interfaces/IUI.h"

class Human : public IPlayer {
    private:
        std::shared_ptr<IUI> ui;

    public:
        Human(std::shared_ptr<IUI>);
        bool Turn(std::shared_ptr<IBoard>) override;
};