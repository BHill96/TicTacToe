#include "Application.h"
#include "structures/GameResults.cpp"

Application::Application(std::unique_ptr<IUI> ui, std::unique_ptr<ITicTacToeGameFactory> gameFactory) {
    this->ui = std::move(ui);
    this->gameFactory = std::move(gameFactory);
}

void Application::Run() {
    GameSettings gameSettings = ui->DisplayGameOptions();
    std::unique_ptr<ITicTacToeGame> tictactoeGame = gameFactory->CreateGame(gameSettings);
    tictactoeGame->PlayGame();
    GameResults gameResults = tictactoeGame->GetResults();
    ui->DisplayGameResults(gameResults);
}