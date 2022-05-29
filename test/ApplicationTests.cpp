// provides unit testing infrastructure
#include "gtest/gtest.h"

#include "Application.h"
#include "mocks/MockUI.h"
#include "mocks/MockGameFactory.h"
#include "mocks/MockTicTacToeGame.h"

class ApplicationTests : public::testing::Test {
	public:
        std::unique_ptr<testing::NiceMock<MockUI>> mockUI;
        std::unique_ptr<testing::NiceMock<MockGameFactory>> mockGameFactory;
        std::unique_ptr<testing::NiceMock<MockTicTacToeGame>> mockTicTacToeGame;

        void SetUp() override {
            mockUI = std::make_unique<testing::NiceMock<MockUI>>();
            mockGameFactory = std::make_unique<testing::NiceMock<MockGameFactory>>();
            mockTicTacToeGame = std::make_unique<testing::NiceMock<MockTicTacToeGame>>();
        }

        Application MakeApp() {
            return Application(std::move(mockUI), std::move(mockGameFactory));
        }

        void FactoryReturnGame() {
            ON_CALL(*mockGameFactory, CreateGame(testing::_))
                .WillByDefault(testing::Return(testing::ByMove(std::move(mockTicTacToeGame))));
        }
};

TEST_F(ApplicationTests, Run_ByDefault_CallDisplayGameOptions) {
    // Arrange
    FactoryReturnGame();

    // Assert
    EXPECT_CALL(*mockUI, DisplayGameOptions());

    // Act
    Application app = MakeApp();
    app.Run();
}

MATCHER_P(EqGameSettings,fact,"") {
    return true;
}

TEST_F(ApplicationTests, Run_ByDefault_CallCreateGame) {
    // Arrange
    GameSettings gameSettings;
    EXPECT_CALL(*mockUI, DisplayGameOptions()).WillOnce(testing::Return(gameSettings));
    FactoryReturnGame();

    // Assert
    EXPECT_CALL(*mockGameFactory, CreateGame(EqGameSettings(gameSettings)));

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallCheckGameState) {
    // Arrange
    std::unique_ptr<testing::NiceMock<MockTicTacToeGame>> mockTicTacToeGame = std::make_unique<testing::NiceMock<MockTicTacToeGame>>();

    // Assert
    EXPECT_CALL(*mockTicTacToeGame, CheckGameState());
    EXPECT_CALL(*mockGameFactory, CreateGame(testing::_))
        .WillOnce(testing::Return(testing::ByMove(std::move(mockTicTacToeGame))));

    // Act
    Application app = MakeApp();
    app.Run();
}
