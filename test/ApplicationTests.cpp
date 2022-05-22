// provides unit testing infrastructure
#include "gtest/gtest.h"
#include "Application.cpp"

class ApplicationTests : public::testing::Test {
	public:
        //std::unique_ptr<testing::NiceMock<MockGame>> mockGame;

        void SetUp() override {
            //mockGame = std::make_unique<testing::NiceMock<MockGame>>();
        }

        Application MakeApp() {
            return Application();
        }
};

TEST_F(ApplicationTests, Run_ByDefault_GameGetStateCalled) {
    // Arrange

    // Act
    ASSERT_TRUE(false);
}
