#include "entities/TicTacToeGame.h"

TicTacToeGame::TicTacToeGame(std::shared_ptr<GameSettings> gameSettings) {
    playerQueue = gameSettings->playerQueue;
    board = gameSettings->board;
}

GameStatus TicTacToeGame::PlayGame() {
    GameStatus status;
    std::shared_ptr<IPlayer> player = playerQueue->Front();
    bool turnFinished = player->Turn(board);
    if (turnFinished) {
        BoardState boardState = board->CheckState();
        if (boardState==BoardState::InProgress) {
            playerQueue->Next();
        }
    //   else if boardState Draw
    //      results.Finished = true;
    //      results.Draw = true;
    //   else if boardState Winner
    //      results.Winner = playerQueue->Front();
    //      playerQueue->Next();
    //      results.Loser = playerQueue->Front(); 
    //      results.Finished = true;
    }
    return status;
}