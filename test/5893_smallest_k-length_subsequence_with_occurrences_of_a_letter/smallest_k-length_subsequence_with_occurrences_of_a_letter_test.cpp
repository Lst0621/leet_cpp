#include <glog/logging.h>

#include "5893_smallest_k-length_subsequence_with_occurrences_of_a_letter/smallest_k-length_subsequence_with_occurrences_of_a_letter_solution.h"
#include "gtest/gtest.h"

using namespace lst::leet;

TEST(SmallestKLengthSubsequenceWithOccurrencesOfALetterTest, LeetTest1) {
    Solution s;
    const auto result = s.smallestSubsequence("leet", 3, 'e', 1);
    ASSERT_EQ("eet", result);
}

TEST(SmallestKLengthSubsequenceWithOccurrencesOfALetterTest, LeetTest2) {
    Solution s;
    const auto result = s.smallestSubsequence(
        "eeeexeeeyexyyeyxeyexyxeyexeexyexxxxyxeye", 7, 'e', 2);
    ASSERT_EQ("eeeeeee", result);
}

TEST(SmallestKLengthSubsequenceWithOccurrencesOfALetterTest, LeetTest3) {
    Solution s;
    const auto result = s.smallestSubsequence(
        "yssyyxyxysyxyxyyysxssyxsssxsxysyyxyyxxysyxsssyyysxyxyssysysyxxxxyxyxxs"
        "ssyyssyyxssxsxysxxysyxxxxsxyssyxsxxsxsyssxsxyysxssyxxsyyyysssssxysxxys"
        "xsyxsysssyyyysyyxsxyxssysssyxxxsxyyxsyxsyxyyysxsxyxxsxyxsssssyyssxxysx"
        "syxyyyysyxssssxsssyyxsxssxssyxssxxyssxyyysxssxysyxyxyyyxsssssxxyxxsyyy"
        "xyxysysysxyxsxsyxyxssyyyyxsyysyxysyxxsxxxsyxxyxyxxxsyxxssxyyyysxyyysxx"
        "yxsysxsyyyxysxxsxyxxyxxxxsyxxyyssxyyxxyysxxyxyyssxsxsxsxsyxsxxyxyxxxsx"
        "yssxxssxyyxssxxxxyxyxxsxsysssxxxsssyxyxyxxxxyxsxxxsysyysxsxsssyyxsxyys"
        "yysxysssyxyxyssyysxxssyyysyyxsxxssysxxxxsysxxxxyxsyxxyxxssyxsyyssyyxsy"
        "yxyxssxxxyyxssyysssyssyxxssxyysxxxysxxsxyxxssssxxsxyyssxxysxxysyxxyxsy"
        "yxsxsxsxxxssyxxsysxyyxxyyxysysyyxsysxysxyxxyyysxssxxxsssxssxsxyysxxxsy"
        "xsyyyyxxsxxxsyysysxyxyyxsyxxyxyyyyyyxssyxxsxxsxsyxysxxsxxxsyxxyxxyxyxy"
        "syyxxsxxsxyxxsssyxyssxsxsxxsyxxsxxsxxssxysxyxyxssssssxsyxxsysyysyxxyxy"
        "yxyxssxyyxsxysxxsyxsxssxxsyxyysxxsxxyysxyysxsyxssyyxxsyyxxyssysxysyyxy"
        "xxssxysysysyyyyssyssysxxsssyxxysxxsxyssxsssyxyxssyssssssssyxysxysxyxxs"
        "xxxxyxssssxxyysxsxsysxxssyyxxxxxsssysyssyyxsxxxsysxsyyxysysxsysysssxsx"
        "ysyyyssxxysxxxxyxyysxysxyysysssxsysxxxyyysyyyxxssssysssxxssyxxssyxyxxx"
        "xssyyxsyyyxsxyxysssyyyysyyxysysxxxsysxsxxyyssxyyyyxsxyyyxssyxxysssyxxs"
        "ssxssysssxyyxsxyyysyssxsyyssyysssssssxxyxsysxsyxxssxyyssxyxxyxsyxxxsyy"
        "xxsyssyyxxxxsxyyysxxxxyxsxxxsxssxxsyyyxsxssxyxssyxyyxyxsx",
        264, 's', 131);
    ASSERT_EQ(
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss"
        "ssssssssssssssssssssssssssssssssssssssssssssssssssssss",
        result);
}
TEST(SmallestKLengthSubsequenceWithOccurrencesOfALetterTest, LeetTest4) {
    Solution s;
    const auto result = s.smallestSubsequence(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaayaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbb"
        "bbbbbbbbbbbbbbbbybbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccycccccccccc"
        "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccycccccccccccc"
        "ccccccccccccccdddddddddddddddddddddddddddddddddddddddddddddydddddddddd"
        "ddddddddddddddddddddddddddddddddddddddddyddddddddddddydeeeyeeeeeeeeeee"
        "eeeeeeeeeeeeeeeeeeeyeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
        "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeyeeeeeeefffffffffffffffffffffffffffffffff"
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
        "fffffffffgggggggggggggggggyggggggggggggggggggggggggggggggggggggggggggg"
        "ggggggggggygyggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
        "gghhyhhhhhhyhhhhhyhhhhhhhhhhhhhhhhhhhhhyhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
        "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiyiiii"
        "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiyiiiiiiiiiiiiiiiiiiiyiiiiiiiiiiiiiiiii"
        "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj"
        "jjyjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjyjjjjjjjjjjjjjjjjjjj"
        "jkkkkkkkkkkkkkkykkkkkkkkkkkykkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkykkkkkk"
        "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkykkkkkkkkkkkkkkkkkkkkllllllylllllllllll"
        "llllllllllllllllllllllylllllllllllllllllllllllllllllllllllllllllllllll"
        "llllllllllllllllllllllllllllllllllllllllllllllmmmmmmmmmmmymmmmmmmmmmmm"
        "mmmmmmmmmmmmmmmmmmmmmmmmmmmymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"
        "mmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnnnnnnnynnnynynnnnnnnnnnnnnnnnnnn"
        "nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn"
        "nnnnnnooooooyoooooooooyooooooooooooooooooooooooooooooooooooooooooooooo"
        "oooooooooooooyoooooooooooooooooyoooooooooooooooooooooooooooooppppppppp"
        "pppppppppppppppppppppppppppppppppppppypppppppppppppppppppppppppppppppp"
        "ppppppppppppppppppppppppppppppppppppqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
        "qqqqqqqqqqqqqqqqqqqyqqqqqqqyqqqqqqqqqqqyqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"
        "qqqqqqyqqqqrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrryrryrr"
        "rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrryrrrrrrrrrysssssssssssssssssss"
        "sssssssssssssssssssssssssssssssssssssssssysssssssssssysssssssyssssssss"
        "ssssssssssssssssssssssssssssstttttttttttttyttttttttttttttttttttttttttt"
        "tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt"
        "ttytttttttttuuuuuuuuuuuuuuuuuuuuuuuuuuyuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu"
        "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvvv"
        "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvyvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv"
        "vvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"
        "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwywwwwywwwwwwwwwwwwwwwxxxxxxx"
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxyyxxxxxxxxxxxxxxxyxxx"
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxyyyy"
        "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy"
        "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzyzzzzzzz"
        "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzyzzzzzzzzzzz"
        "zzzzzzzzzzzzzzzzzzzzzzzzzzyzzz",
        343, 'y', 65);
    EXPECT_EQ(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbb"
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
        "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccccccccccccccccyy"
        "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy",
        result);
}

TEST(SmallestKLengthSubsequenceWithOccurrencesOfALetterTest, LeetTest5) {
    Solution s;
    const auto result = s.smallestSubsequence("leetcode", 4, 'e', 2);
    EXPECT_EQ("ecde", result);
}

TEST(SmallestKLengthSubsequenceWithOccurrencesOfALetterTest, LeetTest6) {
    Solution s;
    const auto result = s.smallestSubsequence(
        "kbcddkkhkjkkmknpqqkttuvvwwxyyabkcekggkklmmnnnooppqsktwwxkaaccdfhhkkkkl"
        "llooppqrsttkvxyykekgkgkkimmmooqrkssvwwxkzzzakbdeffhiimkkoqqrrtkvkkkzzb"
        "bceffghhikkoorsvkxkyzbcccdkhhijkllokkrkssvvvkkkkbdkekfkklknnokppssukww"
        "yzaccddeggiklllkpkpkrtwxyaabcdddkkiiijjkkklkmmnosttvxycckfgghjkknopkqr"
        "skuvvwbbbddkgijklmqrssuvwkwxyeiikkjkklmmnokpkkssttvvwxyzkkcdeekfggghhh"
        "jjkklmmoqkssskkkbbkdffghhhiikjklloppqstttvabbekhhjkkkklkokrstvxykabdef"
        "kkklmmmokppkpkrtukkwwyzaadeggikkmmmkpqrtuxxyk",
        380, 'k', 96);
    EXPECT_EQ(
        "aaaccdfhhkkkkkkekgkgkkikkzzzakbdeffhiimkkoqqrrtkvkkkzzbbceffghhikkoors"
        "vkxkyzbcccdkhhijkllokkrkssvvvkkkkbdkekfkklknnokppssukwwyzaccddeggiklll"
        "kpkpkrtwxyaabcdddkkiiijjkkklkmmnosttvxycckfgghjkknopkqrskuvvwbbbddkgij"
        "klmqrssuvwkwxyeiikkjkklmmnokpkkssttvvwxyzkkcdeekfggghhhjjkklmmoqkssskk"
        "kbbkdffghhhiikjklloppqstttvabbekhhjkkkklkokrstvxykabdefkkklmmmokppkpkr"
        "tukkwwyzaadeggikkmmmkpqrtuxxyk",
        result);
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
