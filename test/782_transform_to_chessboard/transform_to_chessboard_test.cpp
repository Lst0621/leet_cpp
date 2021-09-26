#include <glog/logging.h>
#include "gtest/gtest.h"

#include "782_transform_to_chessboard/transform_to_chessboard_solution.h"

using namespace lst::leet;

TEST(TransformToChessboardTest, LeetTest1) {
    Solution s;
    vector<vector<int>> board = {
        {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}};
    EXPECT_EQ(2, s.movesToChessboard(board));
}
TEST(TransformToChessboardTest, LeetTest2) {
    Solution s;
    vector<vector<int>> board = {{0, 1}, {1, 0}};
    EXPECT_EQ(0, s.movesToChessboard(board));
}

TEST(TransformToChessboardTest, LeetTest3) {
    Solution s;
    vector<vector<int>> board = {{1, 0}, {1, 0}};
    EXPECT_EQ(-1, s.movesToChessboard(board));
}

int main(int argc, char **argv) {
    google::InstallFailureSignalHandler();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
