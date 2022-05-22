// provides unit testing infrastructure
#include "gtest/gtest.h"

#include "Application.h"
#include "mocks/MockUI.h"

class ApplicationTests : public::testing::Test {
	public:
        std::unique_ptr<testing::NiceMock<MockUI>> mockUI;

        void SetUp() override {
            mockUI = std::make_unique<testing::NiceMock<MockUI>>();
        }

        Application MakeApp() {
            return Application(std::move(mockUI));
        }
};

TEST_F(ApplicationTests, Run_ByDefault_GameGetStateCalled) {
    // Arrange

    // Assert
    EXPECT_CALL(*mockUI, DisplayGameConfiguration());

    // Act
    Application app = MakeApp();
    app.Run();
}
