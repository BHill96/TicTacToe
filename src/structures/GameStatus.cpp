#pragma once

#include "interfaces/IPlayer.h"
#include <memory>

struct GameStatus {
    bool Finished = false;
    bool Draw = false;
    std::shared_ptr<IPlayer> Winner;
    std::shared_ptr<IPlayer> Loser;
    std::shared_ptr<IBoard> Board;
};