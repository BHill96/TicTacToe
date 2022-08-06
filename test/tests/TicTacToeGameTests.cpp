// provides unit testing infrastructure
#include "gtest/gtest.h"

#include "entities/TicTacToeGame.h"
#include "mocks/MockPlayerQueue.h"
#include "mocks/MockPlayer.h"
#include "mocks/MockBoard.h"

class TicTacToeGameTests : public::testing::Test {
	public:
        std::shared_ptr<testing::NiceMock<MockPlayer>> mockPlayer;
        std::shared_ptr<testing::NiceMock<MockPlayerQueue>> mockPlayerQueue;
        std::shared_ptr<testing::NiceMock<MockBoard>> mockBoard;

        void SetUp() override {
            mockPlayer = std::make_shared<testing::NiceMock<MockPlayer>>();
            mockPlayerQueue = std::make_shared<testing::NiceMock<MockPlayerQueue>>();
            mockBoard = std::make_shared<testing::NiceMock<MockBoard>>();
        }

        std::shared_ptr<GameSettings> MakeGameSettings() {
            return std::make_shared<GameSettings>(
                GameSettings {
                    .playerQueue = mockPlayerQueue,
                    .board = mockBoard}
            );
        }

        TicTacToeGame MakeTicTacToeGame(std::shared_ptr<GameSettings> settings) {
            return TicTacToeGame(settings);
        }

        void PlayerQueueReturnPlayer() {
            ON_CALL(*mockPlayerQueue, Front())
                .WillByDefault(testing::Return(mockPlayer));
        }

        void PlayerTurnFinished() {
            ON_CALL(*mockPlayer, Turn(testing::_))
                .WillByDefault(testing::Return(true));
        }

        void BoardStateIs(BoardState state) {
            ON_CALL(*mockBoard, CheckState())
                .WillByDefault(testing::Return(state));
        }
};

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_playerQueueFrontCalled) {
    // Arrange

    // Assert
    EXPECT_CALL(*mockPlayerQueue, Front())
        .WillOnce(testing::Return(mockPlayer));

    // Act
    TicTacToeGame game = MakeTicTacToeGame(MakeGameSettings());
    GameStatus _ = game.PlayGame();
}

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_playerTurnCalled) {
    // Arrange
    PlayerQueueReturnPlayer();
    
    // Assert
    EXPECT_CALL(*mockPlayer, Turn(testing::TypedEq<std::shared_ptr<IBoard>>(mockBoard)));

    // Act
    TicTacToeGame game = MakeTicTacToeGame(MakeGameSettings());
    GameStatus _ = game.PlayGame();
}

MATCHER_P(EqGameStatus, status, "") {
    bool finished = arg.Finished == status.Finished;
    bool draw = arg.Draw == status.Draw;
    bool winner = arg.Winner == status.Winner;
    bool loser = arg.Loser == status.Loser;
    return finished && draw && winner && loser;
}

TEST_F(TicTacToeGameTests, PlayGame_TurnNotFinished_ReturnEmptyGameStatus) {
    // Arrange
    PlayerQueueReturnPlayer();
    ON_CALL(*mockPlayer, Turn(testing::TypedEq<std::shared_ptr<IBoard>>(mockBoard)))
        .WillByDefault(testing::Return(false));

    // Act
    TicTacToeGame game = MakeTicTacToeGame(MakeGameSettings());
    GameStatus status = game.PlayGame();

    // Assert
    GameStatus trueStatus;
    EXPECT_THAT(status, EqGameStatus(trueStatus));
}

TEST_F(TicTacToeGameTests, PlayGame_PlayerTurnFinished_CheckBoardState) {
    // Arrange
    PlayerQueueReturnPlayer();
    PlayerTurnFinished();
    
    // Assert
    EXPECT_CALL(*mockBoard, CheckState());

    // Act
    TicTacToeGame game = MakeTicTacToeGame(MakeGameSettings());
    GameStatus _ = game.PlayGame();
}

TEST_F(TicTacToeGameTests, PlayGame_BoardStateInProgress_CallPlayerQueueNext) {
    // Arrange
    PlayerQueueReturnPlayer();
    PlayerTurnFinished();
    BoardStateIs(BoardState::InProgress);
    
    // Assert
    EXPECT_CALL(*mockPlayerQueue, Next());

    // Act
    TicTacToeGame game = MakeTicTacToeGame(MakeGameSettings());
    GameStatus _ = game.PlayGame();
}

TEST_F(TicTacToeGameTests, PlayGame_BoardStateDraw_CreateDrawResults) {
    // Arrange
    PlayerQueueReturnPlayer();
    PlayerTurnFinished();
    BoardStateIs(BoardState::Draw);

    // Act
    TicTacToeGame game = MakeTicTacToeGame(MakeGameSettings());
    GameStatus status = game.PlayGame();

    // Assert
    GameStatus trueStatus {
        .Finished = true,
        .Draw = true
    };
    EXPECT_THAT(status, EqGameStatus(trueStatus));
}

TEST_F(TicTacToeGameTests, PlayGame_BoardStateWinner_CreateWinnerResults) {
    // Arrange
    std::shared_ptr<testing::NiceMock<MockPlayer>> mockPlayer1 =
        std::make_shared<testing::NiceMock<MockPlayer>>();
    std::shared_ptr<testing::NiceMock<MockPlayer>> mockPlayer2 =
        std::make_shared<testing::NiceMock<MockPlayer>>();
    EXPECT_CALL(*mockPlayerQueue, Front())
        .WillOnce(testing::Return(mockPlayer))
        .WillOnce(testing::Return(mockPlayer1))
        .WillOnce(testing::Return(mockPlayer2));
    PlayerTurnFinished();
    BoardStateIs(BoardState::Winner);
    EXPECT_CALL(*mockPlayerQueue, Next());

    // Act
    TicTacToeGame game = MakeTicTacToeGame(MakeGameSettings());
    GameStatus status = game.PlayGame();

    // Assert
    GameStatus trueStatus {
        .Finished = true,
        .Winner = mockPlayer1,
        .Loser = mockPlayer2,
    };
    EXPECT_THAT(status, EqGameStatus(trueStatus));
}