#pragma once

#include "interfaces/IPlayerQueue.h"
#include <vector>

class PlayerQueue : public IPlayerQueue {
    private:
        std::vector<std::shared_ptr<IPlayer>> players;
        int front = 0;

    public:
        PlayerQueue(std::vector<std::shared_ptr<IPlayer>>);
        ~PlayerQueue() = default;
        std::shared_ptr<IPlayer> Front() override;
        void Next() override;
};