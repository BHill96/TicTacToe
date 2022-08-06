#include "entities/TicTacToeGame.h"

TicTacToeGame::TicTacToeGame(GameSettings gameSettings) {
    playerQueue = gameSettings.playerQueue;
    board = gameSettings.board;
}

GameStatus TicTacToeGame::PlayGame() {
    GameStatus status;
    std::shared_ptr<IPlayer> player = playerQueue->Front();
    bool turnFinished = player->Turn(board);
    if (turnFinished) {
        BoardState boardState = board->CheckState();
        if (boardState == BoardState::InProgress) {
            playerQueue->Next();
        } else if (boardState == BoardState::Draw) {
            status.Finished = true;
            status.Draw = true;
        } else if (boardState == BoardState::Winner) {
            status.Finished = true;
            status.Winner = playerQueue->Front();
            playerQueue->Next();
            status.Loser = playerQueue->Front(); 
        }
    }
    return status;
}