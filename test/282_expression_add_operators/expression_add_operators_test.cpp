#include <glog/logging.h>

#include "282_expression_add_operators/expression_add_operators_solution.h"
#include "gtest/gtest.h"

using namespace lst::leet;

void helper(const string &num, int target, vector<string> results) {
    Solution s;
    cout << "test case: " << num << " " << target << endl;
    auto ret = s.addOperators(num, target);
    for (auto &str : ret) {
        cout << "result " << str << endl;
    }
    set<string> s1(results.begin(), results.end());
    set<string> s2(ret.begin(), ret.end());
    EXPECT_EQ(s1, s2);
}

TEST(ExpressionAddOperatorsTest, LeetTest1) {
    helper("123", 6, {"1*2*3", "1+2+3"});
}
TEST(ExpressionAddOperatorsTest, LeetTest2) {
    helper("232", 8, {"2*3+2", "2+3*2"});
}
TEST(ExpressionAddOperatorsTest, LeetTest3) {
    helper("00", 0, {"0*0", "0+0", "0-0"});
}
TEST(ExpressionAddOperatorsTest, LeetTest4) {
    helper("3456237490", 9191, {});
}
TEST(ExpressionAddOperatorsTest, LeetTest5) {
    helper("2147483648", -2147483648, {});
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
