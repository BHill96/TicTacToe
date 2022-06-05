#include "entities/TicTacToeGame.h"

TicTacToeGame::TicTacToeGame(std::shared_ptr<GameSettings> gameSettings) {
    playerQueue = gameSettings->playerQueue;
    board = gameSettings->board;
}

GameResults TicTacToeGame::PlayGame() {
    std::shared_ptr<IPlayer> player = playerQueue->Front();
    player->Turn(board);
    playerQueue->Next();
}