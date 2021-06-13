// provides unit testing infrastructure
#include "gtest/gtest.h"

TEST(Example, willPass)
{
    ASSERT_EQ(5, 5);
}

TEST(Example, willFail)
{
    ASSERT_EQ(4, 5);
}
