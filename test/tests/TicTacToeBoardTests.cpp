#include "gtest/gtest.h"

#include "entities/TicTacToeBoard.h"

class TicTacToeBoardTests : public::testing::Test {
    public:
        TicTacToeBoard MakeTicTacToeBoard() {
            return TicTacToeBoard();
        }

        TicTacToeBoard MakeBoardDrawState(TicTacToeBoard board) {
            board.Update(std::make_unique<Move>(
                Move {.Row = 0, .Column = 0, .Symbol = 'X'}
            ));
            board.Update(std::make_unique<Move>(
                Move {.Row = 1, .Column = 0, .Symbol = 'O'}
            ));
            board.Update(std::make_unique<Move>(
                Move {.Row = 2, .Column = 0, .Symbol = 'X'}
            ));
            board.Update(std::make_unique<Move>(
                Move {.Row = 0, .Column = 1, .Symbol = 'X'}
            ));
            board.Update(std::make_unique<Move>(
                Move {.Row = 1, .Column = 1, .Symbol = 'O'}
            ));
            board.Update(std::make_unique<Move>(
                Move {.Row = 2, .Column = 1, .Symbol = 'X'}
            ));
            board.Update(std::make_unique<Move>(
                Move {.Row = 0, .Column = 2, .Symbol = 'O'}
            ));
            board.Update(std::make_unique<Move>(
                Move {.Row = 1, .Column = 2, .Symbol = 'X'}
            ));
            board.Update(std::make_unique<Move>(
                Move {.Row = 2, .Column = 2, .Symbol = 'O'}
            ));
            return board;
        }
};

TEST_F(TicTacToeBoardTests, Update_CheckState_InProgressState) {
    // Arrange
    TicTacToeBoard board = MakeTicTacToeBoard();

    // Act
    BoardState state = board.CheckState();

    // Assert
    ASSERT_EQ(state, BoardState::InProgress);
}

TEST_F(TicTacToeBoardTests, Update_CheckState_DrawState) {
    // Arrange
    TicTacToeBoard board = MakeTicTacToeBoard();
    board = MakeBoardDrawState(board);

    // Act
    BoardState state = board.CheckState();

    // Assert
    ASSERT_EQ(state, BoardState::Draw);
}

// Wee need all eight combinations. Can we create a data test?
TEST_F(TicTacToeBoardTests, Update_CheckState_WinnerState) {
    // Arrange
    TicTacToeBoard board = MakeTicTacToeBoard();
    board.Update(std::make_unique<Move>(
        Move {.Row = 0, .Column = 0, .Symbol = 'O'}
    ));
    board.Update(std::make_unique<Move>(
        Move {.Row = 1, .Column = 1, .Symbol = 'O'}
    ));
    board.Update(std::make_unique<Move>(
        Move {.Row = 2, .Column = 2, .Symbol = 'O'}
    ));

    // Act
    BoardState state = board.CheckState();

    // Assert
    ASSERT_EQ(state, BoardState::Winner);
}