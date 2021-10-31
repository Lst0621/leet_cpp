#include <glog/logging.h>
#include <gtest/gtest.h>

#include "5917_check_if_an_original_string_exists_given_two_encoded_strings/check_if_an_original_string_exists_given_two_encoded_strings_solution.h"

using namespace lst::leet;

TEST(CheckIfAnOriginalStringExistsGivenTwoEncodedStringsTest, LeetTest1) {
    string s1 = "internationalization";
    string s2 = "i18n";
    Solution s;
    bool result = s.possiblyEquals(s1, s2);
    EXPECT_EQ(true, result);
}
TEST(CheckIfAnOriginalStringExistsGivenTwoEncodedStringsTest, LeetTest2) {
    string s1 = "l123e";
    string s2 = "44";
    Solution s;
    bool result = s.possiblyEquals(s1, s2);
    EXPECT_EQ(true, result);
}
TEST(CheckIfAnOriginalStringExistsGivenTwoEncodedStringsTest, LeetTest3) {
    string s1 = "a5b";
    string s2 = "c5b";
    Solution s;
    bool result = s.possiblyEquals(s1, s2);
    EXPECT_EQ(false, result);
}
TEST(CheckIfAnOriginalStringExistsGivenTwoEncodedStringsTest, LeetTest4) {
    string s1 = "112s";
    string s2 = "g841";
    Solution s;
    bool result = s.possiblyEquals(s1, s2);
    EXPECT_EQ(true, result);
}
TEST(CheckIfAnOriginalStringExistsGivenTwoEncodedStringsTest, LeetTest5) {
    string s1 = "ab";
    string s2 = "a2";
    Solution s;
    bool result = s.possiblyEquals(s1, s2);
    EXPECT_EQ(false, result);
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
