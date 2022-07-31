#include "Application.h"
#include "structures/GameResults.cpp"

Application::Application(std::unique_ptr<IUI> ui, std::unique_ptr<ITicTacToeGameFactory> gameFactory) {
    this->ui = std::move(ui);
    this->gameFactory = std::move(gameFactory);
}

void Application::Run() {
    std::unique_ptr<ITicTacToeGame> tictactoeGame = nullptr;
    GameResults gameResults;

    ui->SetUp();
    do {
        ui->CheckWindowForChanges();
        GameSettings gameSettings = ui->DisplayGameOptions();
        
        if (gameSettings.createGame) {
            tictactoeGame = gameFactory->CreateGame(gameSettings);
        }
        if (tictactoeGame) {
            gameResults = tictactoeGame->PlayGame();
            if (gameResults.Finished) {
                ui->DisplayGameResults(gameResults);
            }
        }

        ui->Render();
    } while (ui->WindowOpen());
 
    ui->Cleanup();
}