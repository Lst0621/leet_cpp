#include <glog/logging.h>
#include <gtest/gtest.h>

#include "7_reverse_integer/reverse_integer_solution.h"

using namespace lst::leet;

TEST(ReverseIntegerTest, LeetTest) {
    Solution s;
    EXPECT_EQ(s.reverse(123), 321);
    EXPECT_EQ(s.reverse(123123), 321321);
    EXPECT_EQ(s.reverse(-123), -321);
    EXPECT_EQ(s.reverse(0), 0);
    EXPECT_EQ(s.reverse(120), 21);
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
