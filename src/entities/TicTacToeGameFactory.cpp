#include "entities/TicTacToeGameFactory.h"
#include "entities/TicTacToeGame.h"

#include <iostream>

std::unique_ptr<ITicTacToeGame> TicTacToeGameFactory::CreateGame(GameSettings gameSettings) {
    std::cout << "Creating TicTacToeGame" << std::endl;
    return std::move(std::make_unique<TicTacToeGame>(gameSettings));
}