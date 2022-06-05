#pragma once

#include "interfaces/IPlayerQueue.h"

#include <memory>

struct GameSettings {
    std::shared_ptr<IPlayerQueue> playerQueue;
    std::shared_ptr<IBoard> board;
};