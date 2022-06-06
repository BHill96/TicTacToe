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
                GameSettings {.playerQueue = mockPlayerQueue,
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

        void ExitPlayGame() {
            ON_CALL(*mockBoard, CheckState())
                .WillByDefault(testing::Return(BoardState::Finished));
        }

        GameResults MakeTrueGameResults(std::shared_ptr<MockPlayer> winner,
            std::shared_ptr<MockPlayer> loser) {
            return GameResults {
                .Winner = winner,
                .Loser = loser,
                .Board = mockBoard
            };
        }
};

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_playerQueueFrontCalled) {
    // Arrange
    ExitPlayGame();

    // Assert
    EXPECT_CALL(*mockPlayerQueue, Front())
        .WillRepeatedly(testing::Return(mockPlayer));

    // Act
    std::shared_ptr<GameSettings> settings = MakeGameSettings();
    TicTacToeGame game = MakeTicTacToeGame(settings);
    GameResults results = game.PlayGame();
}

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_playerTurnCalled) {
    // Arrange
    PlayerQueueReturnPlayer();
    ExitPlayGame();
    
    // Assert
    EXPECT_CALL(*mockPlayer, Turn(testing::TypedEq<std::shared_ptr<IBoard>>(mockBoard)));

    // Act
    std::shared_ptr<GameSettings> settings = MakeGameSettings();
    TicTacToeGame game = MakeTicTacToeGame(settings);
    GameResults results = game.PlayGame();
}

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_boardCheckStateCalled) {
    // Arrange
    PlayerQueueReturnPlayer();
    ExitPlayGame();
    
    // Assert
    EXPECT_CALL(*mockBoard, CheckState());

    // Act
    std::shared_ptr<GameSettings> settings = MakeGameSettings();
    TicTacToeGame game = MakeTicTacToeGame(settings);
    GameResults results = game.PlayGame();
}

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_playerQueueNextCalled) {
    // Arrange
    PlayerQueueReturnPlayer();
    ExitPlayGame();
    
    // Assert
    EXPECT_CALL(*mockPlayerQueue, Next()).Times(2);

    // Act
    std::shared_ptr<GameSettings> settings = MakeGameSettings();
    TicTacToeGame game = MakeTicTacToeGame(settings);
    GameResults results = game.PlayGame();
}

MATCHER_P(EqGameResults, result, "") {
    bool winners = result.Winner == arg.Winner;
    bool losers = result.Loser == arg.Loser;
    bool board = result.Board == arg.Board;
    return winners && losers;
}

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_CreateProperGameResults) {
    // Arrange
    ExitPlayGame();
    std::shared_ptr<testing::NiceMock<MockPlayer>> winner
        = std::make_shared<testing::NiceMock<MockPlayer>>();
    std::shared_ptr<testing::NiceMock<MockPlayer>> loser
        = std::make_shared<testing::NiceMock<MockPlayer>>();

    // AssertW
    EXPECT_CALL(*mockPlayerQueue, Front())
        .WillOnce(testing::Return(mockPlayer))
        .WillOnce(testing::Return(loser))
        .WillOnce(testing::Return(winner));

    // Act
    std::shared_ptr<GameSettings> settings = MakeGameSettings();
    TicTacToeGame game = MakeTicTacToeGame(settings);
    GameResults results = game.PlayGame();

    // Assert
    GameResults trueResults = MakeTrueGameResults(winner, loser);
    EXPECT_THAT(results, EqGameResults(trueResults));
}