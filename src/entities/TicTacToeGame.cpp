#include "entities/TicTacToeGame.h"

TicTacToeGame::TicTacToeGame(std::shared_ptr<GameSettings> gameSettings) {
    playerQueue = gameSettings->playerQueue;
    board = gameSettings->board;
}

GameResults TicTacToeGame::PlayGame() {
    BoardState boardState = BoardState::InProgress;
    do {
        std::shared_ptr<IPlayer> player = playerQueue->Front();
        player->Turn(board);
        boardState = board->CheckState();
        playerQueue->Next();
    } while (boardState == BoardState::InProgress);

    std::shared_ptr<IPlayer> loser = playerQueue->Front();
    playerQueue->Next();
    std::shared_ptr<IPlayer> winner = playerQueue->Front();
    return GameResults {
        .Loser = loser,
        .Winner = winner,
        .Board = board
    };
}