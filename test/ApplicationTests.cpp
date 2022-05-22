// provides unit testing infrastructure
#include "gtest/gtest.h"

#include "Application.h"
#include "mocks/MockUI.h"
#include "mocks/MockGameFactory.h"

class ApplicationTests : public::testing::Test {
	public:
        std::unique_ptr<testing::NiceMock<MockUI>> mockUI;
        std::unique_ptr<testing::NiceMock<MockGameFactory>> mockGameFactory;

        void SetUp() override {
            mockUI = std::make_unique<testing::NiceMock<MockUI>>();
            mockGameFactory = std::make_unique<testing::NiceMock<MockGameFactory>>();
        }

        Application MakeApp() {
            return Application(std::move(mockUI), std::move(mockGameFactory));
        }
};

TEST_F(ApplicationTests, Run_ByDefault_CallDisplayGameOptions) {
    // Arrange

    // Assert
    EXPECT_CALL(*mockUI, DisplayGameOptions());

    // Act
    Application app = MakeApp();
    app.Run();
}

TEST_F(ApplicationTests, Run_ByDefault_CallCreateGame) {
    // Arrange
    GameSettings gameSettings;
    ON_CALL(*mockUI, DisplayGameOptions()).WillByDefault(testing::Return(gameSettings));

    // Assert
    EXPECT_CALL(*mockGameFactory, CreateGame(testing::_));

    // Act
    Application app = MakeApp();
    app.Run();
}

//TEST_F(ApplicationTests, Run_ByDefault_
