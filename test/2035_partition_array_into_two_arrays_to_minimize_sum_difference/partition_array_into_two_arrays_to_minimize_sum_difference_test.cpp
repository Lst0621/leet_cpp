#include <glog/logging.h>

#include "2035_partition_array_into_two_arrays_to_minimize_sum_difference/partition_array_into_two_arrays_to_minimize_sum_difference_solution.h"
#include "gtest/gtest.h"

using namespace lst::leet;

TEST(PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTest, LeetTest1) {
    Solution s;
    int actual = s.minimumDifference({76, 8, 45, 20, 74, 84, 28, 1});
    EXPECT_EQ(2, actual);
}

TEST(PartitionArrayIntoTwoArraysToMinimizeSumDifferenceTest, LeetTest2) {
    Solution s;
    int actual = s.minimumDifference(
        {-4749,    -280997,  -2925043, -108086,  -3101065, -87846,
         109262,   -3017350, -2860312, -2976053, 68165,    -3340774,
         -3035339, 65656,    150572,   -2821790, -3118169, 186745,
         -194026,  -80583,   110376,   242482,   293078,   -8792,
         179088,   128072,   -223621,  279696,   240744,   -288968});
    EXPECT_EQ(31, actual);
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
