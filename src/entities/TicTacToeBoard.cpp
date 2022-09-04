#include "entities/TicTacToeBoard.h"

TicTacToeBoard::TicTacToeBoard() {
    board = std::vector<std::vector<char>> {
        {emptyChar,emptyChar,emptyChar},
        {emptyChar,emptyChar,emptyChar},
        {emptyChar,emptyChar,emptyChar}
    };
}

BoardState TicTacToeBoard::CheckState() {
    bool firstDiagonal = board[0][0]!=emptyChar && board[0][0]==board[1][1] && board[0][0]==board[2][2];
    bool secondDiagonal = board[2][0]!=emptyChar && board[2][0]==board[1][1] && board[2][0]==board[0][2];
    bool firstRow = board[0][0]!=emptyChar && board[0][0]==board[0][1] && board[0][0]==board[0][2];
    bool secondRow = board[1][0]!=emptyChar && board[1][0]==board[1][1] && board[1][0]==board[1][2];
    bool thirdRow = board[2][0]!=emptyChar && board[2][0]==board[2][1] && board[2][0]==board[2][2];
    bool firstColumn = board[0][0]!=emptyChar && board[0][0]==board[1][0] && board[0][0]==board[2][0];
    bool secondColumn = board[0][1]!=emptyChar && board[0][1]==board[1][1] && board[0][1]==board[2][1];
    bool thirdColumn = board[0][2]!=emptyChar && board[0][2]==board[1][2] && board[0][2]==board[2][2];
    if (firstDiagonal || secondDiagonal || firstRow || secondRow ||
        thirdRow || firstColumn || secondColumn || thirdColumn) {
        return BoardState::Winner;
    }

    bool isDraw = true;
    for (int i = 0; i < 3; i++) {
        for (int i = 0; i < 3; i++) {
            if (board[i][i]==emptyChar) {
                isDraw = false;
                break;
            }
        }
    }

    if (isDraw) {
        return BoardState::Draw;
    } else {
        return BoardState::InProgress;
    }
}

void TicTacToeBoard::Update(std::unique_ptr<Move> move) {
    board[move->Row][move->Column] = move->Symbol;
}

char TicTacToeBoard::Get(int row, int col) {
    return board[row][col];
}