#include <glog/logging.h>
#include "gtest/gtest.h"

#include "224_basic_calculator/basic_calculator_solution.h"

using namespace lst::leet;

TEST(BasicCalculatorTest, LeetTest) {
    Solution s;
    EXPECT_EQ(2, s.calculate("1+1"));
    EXPECT_EQ(3, s.calculate(" 2-1 + 2 "));
    EXPECT_EQ(23, s.calculate("(1+(4+5+2)-3)+(6+8)"));
    EXPECT_EQ(10, s.calculate("1+2+3-(-3+4-5)"));
    EXPECT_EQ(2147483647, s.calculate("2147483647"));
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
