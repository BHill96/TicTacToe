#pragma once

#include "interfaces/IPlayer.h"
#include <memory>

struct GameResults {
    bool Finished = false;
    std::shared_ptr<IPlayer> Winner;
    std::shared_ptr<IPlayer> Loser;
    std::shared_ptr<IBoard> Board;
};