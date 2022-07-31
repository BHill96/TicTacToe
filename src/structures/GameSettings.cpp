#pragma once

#include "interfaces/IPlayerQueue.h"

#include <memory>

struct GameSettings {
    bool createGame = false;
    std::shared_ptr<IPlayerQueue> playerQueue;
    std::shared_ptr<IBoard> board;
};