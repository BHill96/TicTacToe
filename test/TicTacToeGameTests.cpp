// provides unit testing infrastructure
#include "gtest/gtest.h"

#include "entities/TicTacToeGame.h"

class TicTacToeGameTests : public::testing::Test {
	public:
        void SetUp() override {
        }

        TicTacToeGame MakeApp() {
            return TicTacToeGame();
        }
};

TEST_F(TicTacToeGameTests, PassingTest) {
    // Arrange

    // Assert
    ASSERT_TRUE(true);

    // Act
}