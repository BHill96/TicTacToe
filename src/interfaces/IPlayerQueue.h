#pragma once

#include "interfaces/IPlayer.h"
#include <memory>

class IPlayerQueue {
    public:
        virtual ~IPlayerQueue() = default;
        virtual std::shared_ptr<IPlayer> Front() = 0;
        virtual void Next() = 0;
};