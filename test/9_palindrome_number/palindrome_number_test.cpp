#include <glog/logging.h>
#include <gtest/gtest.h>

#include "9_palindrome_number/palindrome_number_solution.h"

using namespace lst::leet;

TEST(PalindromeNumberTest, LeetTest) {
    Solution s;

    // true
    EXPECT_TRUE(s.isPalindrome(0));
    EXPECT_TRUE(s.isPalindrome(1));
    EXPECT_TRUE(s.isPalindrome(121));

    // false
    EXPECT_FALSE(s.isPalindrome(-1));
    EXPECT_FALSE(s.isPalindrome(-44));
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
