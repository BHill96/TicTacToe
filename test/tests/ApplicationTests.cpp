// provides unit testing infrastructure
#include "gtest/gtest.h"

#include "entities/Application.h"
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

        void FactoryReturnsGame() {
            ON_CALL(*mockGameFactory, CreateGame(testing::_))
                .WillByDefault(testing::Return(testing::ByMove(std::move(mockTicTacToeGame))));
        }
};

TEST_F(ApplicationTests, Run_ByDefault_CallDisplayGameOptions) {
    // Arrange
    FactoryReturnsGame();

    // Assert
    EXPECT_CALL(*mockUI, DisplayGameOptions());

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallCreateGame) {
    // Arrange
    GameSettings gameSettings;
    EXPECT_CALL(*mockUI, DisplayGameOptions()).WillOnce(testing::Return(gameSettings));
    FactoryReturnsGame();

    // Assert
    EXPECT_CALL(*mockGameFactory, CreateGame(testing::A<GameSettings>()));

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallPlayGame) {
    // Arrange

    // Assert
    EXPECT_CALL(*mockTicTacToeGame, PlayGame());
    FactoryReturnsGame();

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallGetResults) {
    // Arrange

    // Assert
    EXPECT_CALL(*mockTicTacToeGame, GetResults());
    FactoryReturnsGame();

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallDisplayGameResults) {
    // Arrange

    // Assert
    EXPECT_CALL(*mockUI, DisplayGameResults(testing::A<GameResults>()));
    FactoryReturnsGame();

    // Act
    Application app = MakeApp();
    app.Run();
}