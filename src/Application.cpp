#include "Application.h"
#include "structures/GameStatus.cpp"

#include <iostream>

Application::Application(std::unique_ptr<IUI> ui, std::unique_ptr<ITicTacToeGameFactory> gameFactory) {
    this->ui = std::move(ui);
    this->gameFactory = std::move(gameFactory);
}

void Application::Run() {
    std::unique_ptr<ITicTacToeGame> tictactoeGame = nullptr;
    GameStatus gameStatus;

    ui->SetUp();
    do {
        ui->CheckWindowForChanges();
        ui->DrawDemoWindow();
        
        GameSettings gameSettings = ui->DisplayGameOptions();
        
        if (gameSettings.createGame) {
            tictactoeGame = std::move(gameFactory->CreateGame(gameSettings));
        }
        if (tictactoeGame) {
            gameStatus = tictactoeGame->PlayGame();
            if (gameStatus.Finished) {
                ui->DisplayGameResults(gameStatus);
            }
        }

        ui->Render();
    } while (ui->WindowOpen());
 
    ui->Cleanup();
}