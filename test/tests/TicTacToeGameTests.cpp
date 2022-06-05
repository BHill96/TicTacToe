// provides unit testing infrastructure
#include "gtest/gtest.h"

#include "entities/TicTacToeGame.h"
#include "mocks/MockPlayerQueue.h"
#include "mocks/MockPlayer.h"

class TicTacToeGameTests : public::testing::Test {
	public:
        std::shared_ptr<testing::NiceMock<MockPlayer>> mockPlayer;
        std::shared_ptr<testing::NiceMock<MockPlayerQueue>> mockPlayerQueue;
        std::shared_ptr<IBoard> board;

        void SetUp() override {
            mockPlayer = std::make_shared<testing::NiceMock<MockPlayer>>();
            mockPlayerQueue = std::make_shared<testing::NiceMock<MockPlayerQueue>>();
            board = std::make_shared<IBoard>();
        }

        std::shared_ptr<GameSettings> MakeGameSettings() {
            return std::make_shared<GameSettings>(
                GameSettings {.playerQueue = mockPlayerQueue, .board = board}
            );
        }

        TicTacToeGame MakeTicTacToeGame(std::shared_ptr<GameSettings> settings) {
            return TicTacToeGame(settings);
        }
};

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_playerQueueFrontCalled) {
    // Arrange
    ON_CALL(*mockPlayerQueue, Front()).WillByDefault(testing::Return(mockPlayer));

    // Assert
    EXPECT_CALL(*mockPlayerQueue, Front());

    // Act
    std::shared_ptr<GameSettings> settings = MakeGameSettings();
    TicTacToeGame game = MakeTicTacToeGame(settings);
    GameResults results = game.PlayGame();
}

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_playerTurnCalled) {
    // Arrange
    ON_CALL(*mockPlayerQueue, Front()).WillByDefault(testing::Return(mockPlayer));
    
    // Assert
    EXPECT_CALL(*mockPlayer, Turn(testing::TypedEq<std::shared_ptr<IBoard>>(board)));

    // Act
    std::shared_ptr<GameSettings> settings = MakeGameSettings();
    TicTacToeGame game = MakeTicTacToeGame(settings);
    GameResults results = game.PlayGame();
}

TEST_F(TicTacToeGameTests, PlayGame_ByDefault_playerQueueNextCalled) {
    // Arrange
    ON_CALL(*mockPlayerQueue, Front()).WillByDefault(testing::Return(mockPlayer));
    
    // Assert
    EXPECT_CALL(*mockPlayerQueue, Next());

    // Act
    std::shared_ptr<GameSettings> settings = MakeGameSettings();
    TicTacToeGame game = MakeTicTacToeGame(settings);
    GameResults results = game.PlayGame();
}