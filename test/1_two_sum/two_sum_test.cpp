#include <glog/logging.h>

#include "1_two_sum/two_sum_solution.h"
#include "gtest/gtest.h"

using namespace lst::leet;

TEST(TwoSumTest, LeetTest) {
    Solution s;
    vector<int> ans = s.twoSum({2, 7, 11, 15}, 9);
    EXPECT_EQ(ans.size(), 2);
    EXPECT_EQ(ans[0], 0);
    EXPECT_EQ(ans[1], 1);
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}