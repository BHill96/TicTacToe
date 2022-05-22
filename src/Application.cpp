#include "Application.h"

Application::Application(std::unique_ptr<IUI> ui) {
    this->ui = std::move(ui);
}

void Application::Run() {
    ui->DisplayGameConfiguration();
    // Create game from settings
    // play game until finished
    // inform user of results
    // ask if they want to play again
}