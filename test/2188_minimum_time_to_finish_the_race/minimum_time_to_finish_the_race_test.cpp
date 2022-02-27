#include <glog/logging.h>
#include <gtest/gtest.h>

#include "2188_minimum_time_to_finish_the_race/minimum_time_to_finish_the_race_solution.h"

using namespace lst::leet;

TEST(MinimumTimeToFinishTheRaceTest, LeetTest1) {
    Solution s;
    EXPECT_EQ(25, s.minimumFinishTime({{1, 10}, {2, 2}, {3, 4}}, 6, 5));
}

TEST(MinimumTimeToFinishTheRaceTest, LeetTest2) {
    Solution s;
    EXPECT_EQ(21, s.minimumFinishTime({{2, 3}, {3, 4}}, 5, 4));
}

TEST(MinimumTimeToFinishTheRaceTest, LeetTest3) {
    Solution s;
    EXPECT_EQ(17395, s.minimumFinishTime({{99, 7}}, 85, 95));
}

TEST(MinimumTimeToFinishTheRaceTest, LeetTest4) {
    Solution s;
    EXPECT_EQ(1405, s.minimumFinishTime(
                        {{96, 3},  {68, 2}, {53, 4}, {60, 8},  {29, 8}, {96, 8},
                         {31, 10}, {5, 4},  {49, 6}, {54, 7},  {90, 7}, {7, 7},
                         {97, 2},  {50, 9}, {34, 2}, {89, 7},  {51, 7}, {73, 3},
                         {42, 4},  {24, 7}, {99, 3}, {34, 10}, {33, 9}, {45, 7},
                         {32, 2},  {59, 2}, {76, 3}, {10, 6},  {78, 7}, {19, 4},
                         {65, 2},  {30, 9}, {10, 5}, {84, 5},  {62, 4}, {87, 2},
                         {59, 8},  {29, 5}, {40, 4}, {76, 6}},
                        15, 71));
}

TEST(MinimumTimeToFinishTheRaceTest, LeetTest5) {
    Solution s;
    EXPECT_EQ(1317,
              s.minimumFinishTime(
                  {{50, 6},  {29, 3}, {47, 8},   {64, 10}, {12, 7},  {53, 7},
                   {73, 7},  {86, 2}, {66, 3},   {38, 4},  {7, 4},   {53, 3},
                   {61, 10}, {89, 7}, {23, 9},   {69, 9},  {72, 10}, {48, 10},
                   {45, 5},  {13, 5}, {97, 6},   {31, 2},  {37, 2},  {10, 2},
                   {92, 5},  {5, 2},  {38, 5},   {82, 8},  {36, 9},  {27, 4},
                   {88, 3},  {99, 3}, {64, 9},   {99, 9},  {89, 6},  {15, 9},
                   {17, 5},  {73, 7}, {56, 6},   {79, 4},  {93, 10}, {50, 2},
                   {43, 3},  {3, 3},  {100, 7},  {1, 2},   {63, 6},  {57, 10},
                   {43, 10}, {72, 9}, {73, 9},   {53, 8},  {49, 2},  {51, 8},
                   {29, 10}, {77, 5}, {100, 10}, {90, 3},  {8, 9},   {41, 2},
                   {40, 2}},
                  47, 88));
}

TEST(MinimumTimeToFinishTheRaceTest, LeetTest6) {
    Solution s;
    EXPECT_EQ(
        2526,
        s.minimumFinishTime(
            {{3, 4},   {84, 2},  {63, 8}, {72, 8},  {82, 7}, {83, 6}, {23, 2},
             {77, 5},  {51, 10}, {28, 2}, {47, 9},  {8, 3},  {48, 3}, {56, 3},
             {8, 10},  {66, 6},  {92, 9}, {44, 6},  {23, 5}, {5, 6},  {86, 9},
             {13, 10}, {91, 3},  {2, 2},  {8, 4},   {67, 8}, {63, 6}, {52, 5},
             {42, 10}, {3, 9},   {66, 5}, {35, 10}, {63, 6}, {65, 6}, {22, 8},
             {40, 9},  {43, 4},  {73, 9}, {81, 5},  {32, 2}, {30, 5}, {80, 9},
             {50, 4},  {35, 4},  {52, 7}, {11, 5},  {7, 8},  {68, 3}, {54, 8},
             {49, 8}},
            90, 87));
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
