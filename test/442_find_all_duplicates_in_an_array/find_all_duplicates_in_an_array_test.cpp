#include <glog/logging.h>
#include <gtest/gtest.h>

#include "442_find_all_duplicates_in_an_array/find_all_duplicates_in_an_array_solution.h"

using namespace lst::leet;

TEST(FindAllDuplicatesInAnArrayTest, LeetTest) {
    Solution s;
    vector<int> input = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ret = s.findDuplicates(input);
    vector<int> ans = {3, 2};
    sort(ans.begin(), ans.end());
    sort(ret.begin(), ret.end());
    EXPECT_EQ(ans, ret);
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
