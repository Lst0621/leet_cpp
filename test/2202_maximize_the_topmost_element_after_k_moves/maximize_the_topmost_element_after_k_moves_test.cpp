#include <glog/logging.h>
#include <gtest/gtest.h>

#include "2202_maximize_the_topmost_element_after_k_moves/maximize_the_topmost_element_after_k_moves_solution.h"

using namespace lst::leet;

TEST(MaximizeTheTopmostElementAfterKMovesTest, LeetTest1) {
    Solution s;
    EXPECT_EQ(5, s.maximumTop({5, 2, 2, 4, 0, 6}, 4));
}

TEST(MaximizeTheTopmostElementAfterKMovesTest, LeetTest2) {
    Solution s;
    EXPECT_EQ(94, s.maximumTop({35, 43, 23, 86, 23, 45, 84, 2,  18, 83, 79, 28,
                                54, 81, 12, 94, 14, 0,  0,  29, 94, 12, 13, 1,
                                48, 85, 22, 95, 24, 5,  73, 10, 96, 97, 72, 41,
                                52, 1,  91, 3,  20, 22, 41, 98, 70, 20, 52, 48,
                                91, 84, 16, 30, 27, 35, 69, 33, 67, 18, 4,  53,
                                86, 78, 26, 83, 13, 96, 29, 15, 34, 80, 16, 49},
                               15));
}

TEST(MaximizeTheTopmostElementAfterKMovesTest, LeetTest3) {
    Solution s;
    EXPECT_EQ(91, s.maximumTop(
                      {91, 98, 17, 79, 15, 55, 47, 86, 4,  5,  17, 79, 68, 60,
                       60, 31, 72, 85, 25, 77, 8,  78, 40, 96, 76, 69, 95, 2,
                       42, 87, 48, 72, 45, 25, 40, 60, 21, 91, 32, 79, 2,  87,
                       80, 97, 82, 94, 69, 43, 18, 19, 21, 36, 44, 81, 99},
                      2));
}

TEST(MaximizeTheTopmostElementAfterKMovesTest, LeetTest4) {
    Solution s;
    EXPECT_EQ(-1, s.maximumTop({18}, 3));
}

TEST(MaximizeTheTopmostElementAfterKMovesTest, LeetTest5) {
    Solution s;
    EXPECT_EQ(-1, s.maximumTop({2}, 1));
}

TEST(MaximizeTheTopmostElementAfterKMovesTest, LeetTest6) {
    Solution s;
    EXPECT_EQ(4, s.maximumTop({4, 6, 1, 0, 6, 2, 4}, 0));
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
