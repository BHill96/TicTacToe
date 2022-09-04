#include "gtest/gtest.h"

#include "mocks/MockBoard.h"
#include "mocks/MockUI.h"
#include "entities/Human.h"

class HumanTests : public::testing::Test {
    public:
        std::shared_ptr<testing::NiceMock<MockUI>> mockUI;
        std::shared_ptr<testing::NiceMock<MockBoard>> mockBoard;

        void SetUp() override {
            mockUI = std::make_shared<testing::NiceMock<MockUI>>();
            mockBoard = std::make_shared<testing::NiceMock<MockBoard>>();
        }

        Human MakeHuman() {
            return Human("junk",'c',mockUI);
        }

};

TEST_F(HumanTests, Turn_ByDefault_DisplayInteractiveBoardCalled) {
    // Assert
    EXPECT_CALL(*mockUI, DisplayInteractiveBoard(testing::_));

    // Act
    bool _ = MakeHuman().Turn(mockBoard);
}

TEST_F(HumanTests, Turn_MoveMade_UpdateBoard) {
    // Assert
    std::unique_ptr<Move> move = std::make_unique<Move>();
    ON_CALL(*mockUI, DisplayInteractiveBoard(testing::_))
        .WillByDefault(testing::Return(testing::ByMove(std::move(move))));
    EXPECT_CALL(*mockBoard, Update(testing::_));

    // Act
    bool _ = MakeHuman().Turn(mockBoard);
}

TEST_F(HumanTests, Turn_MoveMade_ReturTrue) {
    // Arrange
    std::unique_ptr<Move> move = std::make_unique<Move>();
    ON_CALL(*mockUI, DisplayInteractiveBoard(testing::_))
        .WillByDefault(testing::Return(testing::ByMove(std::move(move))));

    // Act/Assert
    EXPECT_TRUE(MakeHuman().Turn(mockBoard));
}

TEST_F(HumanTests, Turn_NoMove_ReturnFalse) {
    // Arrange
    ON_CALL(*mockUI, DisplayInteractiveBoard(testing::_))
        .WillByDefault(testing::Return(testing::ByMove(std::move(nullptr))));
    
    // Act/Assert
    EXPECT_FALSE(MakeHuman().Turn(mockBoard));
}