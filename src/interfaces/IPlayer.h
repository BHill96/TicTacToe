#pragma once

#include "interfaces/IBoard.h"
#include <memory>

class IPlayer {
    public:
        virtual bool Turn(std::shared_ptr<IBoard>) = 0;
};