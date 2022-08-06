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

    std::cout << "Setting up..." << std::endl;
    ui->SetUp();
    do {
        std::cout << "Creating Window..." << std::endl;
        ui->CheckWindowForChanges();
        std::cout << "Creating Demo Window..." << std::endl;
        ui->DrawDemoWindow();
        
        std::cout << "DisplayGameOptions..." << std::endl;
        GameSettings gameSettings = ui->DisplayGameOptions();
        
        std::cout << "Create Game: " << gameSettings.createGame << std::endl;
        if (gameSettings.createGame) {
            std::cout << "Creating Game..." << std::endl;
            tictactoeGame = gameFactory->CreateGame(gameSettings);
        }
        if (tictactoeGame) {
            std::cout << "Playing Game..." << std::endl;
            gameStatus = tictactoeGame->PlayGame();
            if (gameStatus.Finished) {
                std::cout << "Displaying Results..." << std::endl;
                ui->DisplayGameResults(gameStatus);
            }
        }

        std::cout << "Rendering..." << std::endl;
        ui->Render();
    } while (ui->WindowOpen());
 
    std::cout << "Cleaning Up..." << std::endl;
    ui->Cleanup();

    std::cout << "Finished." << std::endl;
}