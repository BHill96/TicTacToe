#include "gtest/gtest.h"

#include "entities/PlayerQueue.h"
#include "mocks/MockPlayer.h"

class PlayerQueueTests : public::testing::Test {
    public:
        std::shared_ptr<testing::NiceMock<MockPlayer>> playerOne;
        std::shared_ptr<testing::NiceMock<MockPlayer>> playerTwo;

        void SetUp() {
            playerOne = std::make_shared<testing::NiceMock<MockPlayer>>();
            playerTwo = std::make_shared<testing::NiceMock<MockPlayer>>();
        }

        PlayerQueue MakePlayerQueue() {
            std::vector<std::shared_ptr<IPlayer>> players {
                playerOne, playerTwo
            };
            return PlayerQueue(players);
        }
};

TEST_F(PlayerQueueTests, Next_ByDefault_ReturnCorrectPlayer) {
    
    PlayerQueue queue = MakePlayerQueue();
    queue.Next();
    std::shared_ptr<IPlayer> player = queue.Front();
    EXPECT_EQ(player, playerTwo);
}
