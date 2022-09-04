#include "entities/Human.h"

Human::Human(std::string name, char symbol, std::shared_ptr<IUI> ui) {
    this->name = name;
    this->symbol = symbol;
    this->ui = ui;
}

bool Human::Turn(std::shared_ptr<IBoard> board) {
    std::unique_ptr<Move> move = ui->DisplayInteractiveBoard(board);
    if (move) {
        board->Update(std::move(move));
        return true;
    }
    
    return false;
}