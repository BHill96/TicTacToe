// provides unit testing infrastructure
#include "gtest/gtest.h"

#include "Application.h"
#include "mocks/MockUI.h"
#include "mocks/MockTicTacToeGameFactory.h"
#include "mocks/MockTicTacToeGame.h"

class ApplicationTests : public::testing::Test {
	public:
        std::unique_ptr<testing::NiceMock<MockUI>> mockUI;
        std::unique_ptr<testing::NiceMock<MockTicTacToeGameFactory>> mockGameFactory;
        std::unique_ptr<testing::NiceMock<MockTicTacToeGame>> mockTicTacToeGame;

        void SetUp() override {
            mockUI = std::make_unique<testing::NiceMock<MockUI>>();
            mockGameFactory = std::make_unique<testing::NiceMock<MockTicTacToeGameFactory>>();
            mockTicTacToeGame = std::make_unique<testing::NiceMock<MockTicTacToeGame>>();
        }

        Application MakeApp() {
            return Application(std::move(mockUI), std::move(mockGameFactory));
        }

        void FactoryReturnsGame() {
            GameSettings gameSettings;
            gameSettings.createGame = true;
            ON_CALL(*mockUI, DisplayGameOptions())
                .WillByDefault(testing::Return(gameSettings));
            ON_CALL(*mockGameFactory, CreateGame(testing::_))
                .WillByDefault(testing::Return(testing::ByMove(std::move(mockTicTacToeGame))));
        }

        void CloseWindow() {
            ON_CALL(*mockUI, WindowOpen())
                .WillByDefault(testing::Return(false));
        }
};

TEST_F(ApplicationTests, Run_ByDefault_CallSetUp) {
    // Arrange
    CloseWindow();

    // Assert
    EXPECT_CALL(*mockUI, SetUp());

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallCheckWindowForChanges) {
    // Arrange
    CloseWindow();

    // Assert
    EXPECT_CALL(*mockUI, CheckWindowForChanges());

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_WindowOpen) {
    // Arrange

    // Assert
    EXPECT_CALL(*mockUI, WindowOpen())
        .WillOnce(testing::Return(true))
        .WillOnce(testing::Return(false));

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallDisplayGameOptions) {
    // Arrange
    CloseWindow();

    // Assert
    EXPECT_CALL(*mockUI, DisplayGameOptions());

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallCreateGame) {
    // Arrange
    GameSettings gameSettings;
    gameSettings.createGame = true;
    EXPECT_CALL(*mockUI, DisplayGameOptions()).WillOnce(testing::Return(gameSettings));
    CloseWindow();

    // Assert
    EXPECT_CALL(*mockGameFactory, CreateGame(testing::A<GameSettings>()));

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallPlayGame) {
    // Arrange
    CloseWindow();

    // Assert
    EXPECT_CALL(*mockTicTacToeGame, PlayGame());
    FactoryReturnsGame();

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallDisplayGameResults) {
    // Arrange
    GameResults gameResults;
    gameResults.Finished = true;
    ON_CALL(*mockTicTacToeGame, PlayGame())
        .WillByDefault(testing::Return(gameResults));

    // Assert
    EXPECT_CALL(*mockUI, DisplayGameResults(testing::A<GameResults>()));
    FactoryReturnsGame();

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallRender) {
    // Arrange
    CloseWindow();
    
    // Assert
    EXPECT_CALL(*mockUI, Render());

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_WindowClosed_CallCleanup) {
    // Arrange
    CloseWindow();
    
    // Assert
    EXPECT_CALL(*mockUI, Cleanup());

    // Act
    Application app = MakeApp();
    app.Run();
}