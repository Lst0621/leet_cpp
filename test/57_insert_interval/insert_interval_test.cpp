#include <glog/logging.h>

#include "57_insert_interval/insert_interval_solution.h"
#include "gtest/gtest.h"

using namespace lst::leet;

TEST(InsertIntervalTest, LeetTest1) {
    Solution s;
    EXPECT_EQ(vector<vector<int>>({{1, 5}, {6, 9}}),
              s.insert({{1, 3}, {6, 9}}, {2, 5}));
}

TEST(InsertIntervalTest, LeetTest2) {
    Solution s;
    EXPECT_EQ(vector<vector<int>>({{1, 2}, {3, 10}, {12, 16}}),
              s.insert({{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}));
}

TEST(InsertIntervalTest, LeetTest3) {
    Solution s;
    EXPECT_EQ(vector<vector<int>>({{5, 7}}), s.insert({}, {5, 7}));
}

TEST(InsertIntervalTest, LeetTest4) {
    Solution s;
    EXPECT_EQ(vector<vector<int>>({{1, 5}}), s.insert({{1, 5}}, {2, 3}));
}

TEST(InsertIntervalTest, LeetTest5) {
    Solution s;
    EXPECT_EQ(vector<vector<int>>({{1, 7}}), s.insert({{1, 5}}, {2, 7}));
}

TEST(InsertIntervalTest, LeetTest6) {
    Solution s;
    EXPECT_EQ(vector<vector<int>>({{0, 0}, {1, 5}}),
              s.insert({{1, 5}}, {0, 0}));
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
