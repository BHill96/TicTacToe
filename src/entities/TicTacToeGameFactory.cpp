#include "entities/TicTacToeGameFactory.h"
#include "entities/TicTacToeGame.h"

std::unique_ptr<ITicTacToeGame> TicTacToeGameFactory::CreateGame(GameSettings gameSettings) {
    return std::move(std::make_unique<TicTacToeGame>(gameSettings));
}