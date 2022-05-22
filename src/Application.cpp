#include "Application.h"

Application::Application(std::unique_ptr<IUI> ui, std::unique_ptr<IGameFactory> gameFactory) {
    this->ui = std::move(ui);
    this->gameFactory = std::move(gameFactory);
}

void Application::Run() {
    GameSettings gameSettings = ui->DisplayGameOptions();
    gameFactory->CreateGame(gameSettings);
    // play game until finished
    // inform user of results
    // ask if they want to play again
}