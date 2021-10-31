#include <glog/logging.h>

#include "5884_the_score_of_students_solving_math_expression/the_score_of_students_solving_math_expression_solution.h"
#include "gtest/gtest.h"

using namespace lst::leet;

TEST(TheScoreOfStudentsSolvingMathExpressionTest, LeetTest1) {
    Solution s;
    vector<int> ans = {20, 13, 42};
    EXPECT_EQ(7, s.scoreOfStudents("7+3*1*2", ans));
}
TEST(TheScoreOfStudentsSolvingMathExpressionTest, LeetTest2) {
    Solution s;
    vector<int> ans = {
        571, 572,  692,  776,  568, 317,  896,  856,  872,  872, 880,  517,
        572, 265,  968,  572,  896, 968,  482,  968,  572,  880, 572,  644,
        704, 572,  572,  968,  872, 572,  920,  632,  812,  572, 976,  572,
        901, 572,  572,  728,  856, 572,  656,  680,  562,  572, 293,  583,
        572, 105,  37,   572,  572, 223,  644,  644,  572,  760, 956,  379,
        908, 968,  947,  572,  572, 31,   692,  828,  704,  572, 572,  932,
        776, 692,  899,  872,  764, 956,  848,  988,  848,  572, 572,  365,
        856, 956,  221,  980,  812, 695,  584,  764,  808,  459, 752,  572,
        481, 537,  928,  760,  572, 896,  505,  572,  572,  70,  474,  1000,
        760, 608,  992,  928,  73,  904,  704,  848,  572,  503, 956,  692,
        856, 678,  370,  851,  872, 716,  968,  572,  411,  304, 980,  752,
        956, 572,  572,  572,  992, 848,  880,  572,  680,  812, 992,  728,
        572, 776,  572,  753,  572, 571,  572,  572,  920,  572, 637,  572,
        808, 770,  332,  856,  572, 704,  572,  644,  856,  417, 808,  944,
        976, 944,  235,  275,  572, 980,  692,  572,  908,  571, 506,  984,
        572, 27,   663,  945,  968, 948,  572,  989,  572,  596, 980,  572,
        994, 327,  383,  620,  980, 572,  872,  764,  132,  674, 596,  491,
        667, 728,  292,  89,   716, 931,  601,  656,  584,  313, 968,  142,
        728, 920,  57,   572,  572, 572,  904,  572,  270,  492, 880,  724,
        620, 552,  395,  932,  572, 808,  980,  572,  584,  925, 572,  572,
        572, 584,  752,  587,  542, 299,  928,  572,  632,  572, 535,  572,
        881, 36,   572,  980,  584, 572,  392,  232,  572,  505, 572,  532,
        709, 992,  856,  215,  608, 638,  572,  144,  375,  968, 980,  596,
        976, 572,  776,  117,  992, 572,  291,  692,  395,  159, 572,  992,
        800, 572,  608,  258,  484, 896,  1000, 632,  637,  856, 976,  692,
        704, 956,  572,  1000, 692, 353,  953,  752,  340,  656, 572,  848,
        608, 988,  120,  904,  609, 1000, 657,  273,  572,  980, 856,  572,
        572, 704,  572,  572,  716, 993,  808,  572,  572,  66,  716,  572,
        680, 920,  525,  956,  572, 704,  118,  752,  572,  880, 585,  572,
        572, 872,  572,  856,  572, 644,  680,  1000, 808,  572, 879,  872,
        856, 848,  572,  632,  572, 572,  572,  745,  533,  596, 920,  656,
        980, 157,  572,  692,  572, 579,  358,  572,  776,  572, 662,  944,
        741, 812,  572,  268,  351, 776,  980,  932,  28,   620, 620,  584,
        992, 760,  572,  764,  956, 981,  572,  896,  1000, 721, 572,  620,
        680, 572,  994,  608,  572, 146,  896,  572,  381,  704, 976,  922,
        173, 956,  692,  776,  572, 320,  920,  221,  896,  572, 184,  760,
        764, 137,  979,  669,  572, 572,  776,  902,  728,  75,  980,  764,
        880, 572,  366,  572,  908, 584,  776,  995,  572,  980, 848,  992,
        572, 680,  495,  572,  488, 889,  473,  808,  597,  586, 73,   992,
        848, 572,  469,  572,  148, 572,  572,  789,  572,  872, 45,   596,
        606, 572,  106,  432,  293, 764,  880,  273,  812,  760, 618,  572,
        904, 848,  944,  572,  908, 468,  536,  728,  956,  968, 808,  572,
        572, 572,  572,  976,  572, 572,  902,  572,  808,  572, 1000, 140,
        320, 572,  277,  584,  572, 572,  572,  572,  572,  572, 572,  275,
        184, 716,  752,  290,  872, 299,  680,  933,  692,  572, 928,  968,
        572, 572,  980,  34,   596, 100,  928,  572,  920,  880, 644,  572,
        968, 572,  896,  908,  848, 400,  21,   584,  976,  478, 620,  608,
        572, 812,  572,  201,  572, 572,  572,  932,  764,  980, 980,  692,
        572, 572,  716,  584,  205, 924,  281,  920,  980,  611, 56,   572,
        572, 716,  643,  764,  572, 866,  596,  928,  904,  956, 704,  976,
        908, 896,  572,  880,  896, 170,  812,  620,  215,  880, 572,  572,
        976, 1000, 680,  146,  572, 572,  644,  572,  608,  872, 305,  572,
        608, 608,  872,  808,  572, 572,  944,  2,    716,  761, 764,  596,
        612, 371,  680,  404,  534, 848,  292,  128,  572,  572, 608,  148,
        572, 644,  572,  331,  483, 572,  646,  572,  671,  760, 969,  920,
        360, 369,  572,  968,  716, 692,  572,  570,  953,  149, 752,  841,
        572, 896,  572,  572,  608, 872,  728,  976,  944,  680, 716,  704,
        896, 608,  572,  896,  338, 572,  488,  848,  992,  549, 617,  130,
        467, 969,  298,  808,  330, 596,  720,  661,  984,  752, 612,  656,
        572, 572,  666,  941,  759, 975,  572,  656,  572,  93,  764,  992,
        880, 728,  572,  572,  596, 920,  572,  812,  608,  572, 596,  181,
        776, 572,  279,  856,  692, 572,  584,  572,  121,  486, 812,  572,
        764, 572,  572,  455,  572, 572,  572,  812,  405,  572, 766,  790,
        620, 572,  572,  692,  572, 728,  896,  764,  912,  242, 6,    572,
        872, 572,  644,  572,  896, 124,  896,  9,    776,  875, 704,  584,
        896, 572,  704,  848,  224, 486,  272,  572,  1000, 976, 572,  880,
        848, 908,  12,   680,  956, 825,  752,  68,   704,  572, 920,  548,
        992, 728,  812,  944,  274, 644,  920,  949,  572,  920, 718,  644,
        896, 626,  956,  572,  904, 572,  932,  572,  572,  572, 572,  575,
        383, 807,  908,  572,  572, 752,  920,  602,  764,  956, 568,  572,
        111, 572,  572,  572,  395, 526,  764,  572,  572,  872, 584,  596,
        572, 920,  410,  572,  908, 572,  101,  692,  161,  992, 596,  992,
        920, 904,  531,  27,   192, 728,  932,  572,  602,  272, 255,  204,
        713, 976,  626,  433,  572, 272,  531,  857,  896,  529, 982,  91,
        992, 916,  752,  589,  992, 572,  299,  856,  572,  760, 572,  572,
        728, 752,  572,  572,  27,  14,   254,  572,  572,  572, 847,  50,
        572, 6,    572,  82,   980, 620,  680,  644,  728,  956, 605,  572,
        155, 684,  246,  468,  656, 79,   752,  226,  572,  852, 97,   572,
        980, 896,  656,  928,  608, 904,  389,  138,  572,  728, 369,  716,
        680, 557,  755,  856,  572, 983,  242,  572,  123,  9,   718,  896,
        178, 572,  896,  818,  572, 810,  956,  812,  687,  871, 623,  620,
        872, 370,  752,  992,  572, 572,  638,  808,  608,  572, 527,  704,
        572, 552,  572,  88,   572, 704,  904,  981,  176,  174, 572,  572,
        572, 893,  342,  976,  268, 584,  133,  1000, 572,  752, 737,  944,
        752, 968,  928,  848,  368, 572,  687,  572,  944,  904, 728,  451,
        584, 596,  872,  685,  538, 572,  572,  572,  692,  572, 28,   248,
        728, 992,  988,  421,  572, 908,  127,  1000, 356,  978, 968,  572,
        88,  511,  572,  572,  920, 713,  752,  572,  904,  572, 976,  21,
        670, 434,  880,  572,  485, 776,  920,  584,  351,  956, 752,  620,
        644, 728,  812,  572,  572, 572,  856,  704,  572,  189, 820,  572,
        856, 572,  572,  572,  147, 956,  572,  572,  572,  572, 572,  620,
        572, 776,  848,  196,  956, 779,  620,  572,  572,  968, 19,   572,
        572, 1000, 572,  584,  896, 336,  908,  572,  992,  980, 624,  680,
        572, 644,  644,  572,  572, 572,  728,  572,  572,  572, 776,  788,
        572, 776,  572,  572,  904, 637,  728,  764,  572,  728, 572,  693,
        752, 572,  572,  572,  980, 716,  608,  315,  716,  406, 546,  805,
        572, 645,  704,  908,  896, 141,  968,  572,  572,  499, 572,  572,
        572, 680,  920,  647,  572, 980,  391,  745,  920,  680, 656,  992,
        90,  719,  572,  944,  572, 12,   716,  166,  764,  716, 812,  857,
        859, 680,  938,  680,  259, 237,  572,  968,  708,  572, 992,  572,
        956, 572,  370,  956,  187, 456,  776,  323,  572,  8,   195,  572,
        808, 608,  783,  357,  992, 572,  872,  572,  572,  572, 572,  644,
        113, 691,  944,  572,  571, 572,  848,  572,  656,  680, 704,  584,
        716, 587,  782,  944,  856, 176,  279,  572,  561,  644, 829,  584,
        244, 264,  572,  880,  872, 776,  812,  928,  248,  904, 994,  226,
        896, 12,   620,  572,  632, 704,  608,  596,  857,  776, 963,  286,
        572, 680,  632,  789,  764, 539,  903,  620,  760,  752, 812,  572,
        644, 700,  572,  608,  572, 620,  760,  221,  620,  680, 748,  936,
        776, 393,  572,  644,  808, 210,  572,  832,  695,  632, 572,  572,
        627, 832,  856,  707,  572, 932,  572,  572,  540,  620, 572,  992,
        572, 572,  709,  704,  760, 760,  572,  231,  572,  704, 596,  572,
        773, 572,  572,  572,  311, 776,  728,  216,  572,  808, 572,  263,
        572, 584,  524,  976,  572, 669,  980,  896,  680,  311, 572,  572,
        904, 692,  467,  572,  572, 466,  812,  572,  35,   735, 753,  808,
        321, 268,  880,  580,  908, 620,  572,  928,  584,  572, 572,  812,
        677, 572,  306,  572,  657, 422,  572,  872,  572,  904, 572,  656,
        872, 72,   944,  812,  620, 704,  762,  716,  644,  608, 692,  728,
        585, 968,  584,  848,  572, 1000, 53,   572,  680,  464, 481,  608,
        782, 632,  728,  968,  875, 632,  920,  572,  572,  928, 203,  572,
        572, 572,  572,  956,  279, 776,  572,  21,   5,    93,  848,  656,
        572, 891,  97,   181,  722, 812,  632,  716,  407,  920, 968,  956,
        896, 764,  620,  656,  513, 572,  968,  572,  610,  572, 776,  896,
        856, 596,  692,  656,  928, 7,    572,  704,  51,   716, 282,  149,
        572, 394,  572,  608,  572, 666,  872,  920,  572,  576, 572,  928,
        460, 656,  992,  572,  985, 571,  572,  692,  609,  601, 856,  856,
        914, 821,  572,  741,  956, 572,  572,  976,  980,  596, 756,  572,
        572, 572,  572,  572,  932, 572,  572,  572,  656,  880, 572,  146,
        644, 908,  572,  928,  423, 572,  992,  376,  764,  848, 904,  958,
        932, 620,  823,  980,  812, 513,  992,  572,  980,  572, 831,  572,
        728, 572,  1000, 830,  872, 992,  812,  980,  231,  761, 572,  572,
        749, 904,  572,  572,  859, 572,  920,  235,  932,  572, 572,  596,
        932, 3,    992,  632,  896, 542,  743,  608,  261,  716, 605,  596,
        186};
    EXPECT_EQ(3422, s.scoreOfStudents("2*6*2*4*4+6*2+4*6+6*4+8*8*2", ans));
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
