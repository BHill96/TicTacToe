#include "entities/PlayerQueue.h"

PlayerQueue::PlayerQueue(std::vector<std::shared_ptr<IPlayer>> players) {
    this->players = players;
}

std::shared_ptr<IPlayer> PlayerQueue::Front() {
    return players[front];
}

void PlayerQueue::Next() {
    front = (front+1)%players.size();
}