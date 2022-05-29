// provides unit testing infrastructure
#include "gtest/gtest.h"

#include "entities/GameFactory.h"

class GameFactoryTests : public::testing::Test {
	public:
        void SetUp() override {
        }

        GameFactory MakeGameFactory() {
            return GameFactory();
        }
};

TEST_F(GameFactoryTests, PassingTest) {
    // Arrange

    // Assert
    ASSERT_TRUE(true);

    // Act
}