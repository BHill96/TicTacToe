#pragma once

#include "interfaces/IBoard.h"
#include <memory>

class IPlayer {
    public:
        virtual void Turn(std::shared_ptr<IBoard>) = 0;
};