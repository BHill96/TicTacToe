#include "Application.h"
#include "structures/GameResults.cpp"

Application::Application(std::unique_ptr<IUI> ui, std::unique_ptr<ITicTacToeGameFactory> gameFactory) {
    this->ui = std::move(ui);
    this->gameFactory = std::move(gameFactory);
}

void Application::Run() {
    GameSettings gameSettings = ui->DisplayGameOptions();
    std::unique_ptr<ITicTacToeGame> tictactoeGame = gameFactory->CreateGame(gameSettings);
    GameResults gameResults = tictactoeGame->PlayGame();
    ui->DisplayGameResults(gameResults);
}