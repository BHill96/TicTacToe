#include <iostream>

#include "Application.h"
#include "ui/GUI.h"
#include "entities/TicTacToeGameFactory.h"

int main() {
    std::cout << "Creating Application..." << std::endl;
    std::unique_ptr<GUI> gui = std::make_unique<GUI>();
    std::unique_ptr<TicTacToeGameFactory> ticTacToeGameFactory = std::make_unique<TicTacToeGameFactory>();
    Application app(std::move(gui), std::move(ticTacToeGameFactory));

    std::cout << "Running Application..." << std::endl;
    app.Run();

    return 0;
}
