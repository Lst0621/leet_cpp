#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    int movesToChessboard(const vector<vector<int>>& board) {
        auto m = board.size();
        auto n = board[0].size();
        int ret = 0;
        {
            // first row
            int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
            for (int i = 0; i < n; i++) {
                int num = board[0][i];
                if (num == 0) {
                    if (i % 2 == 0) {
                        c00++;
                    } else {
                        c01++;
                    }
                } else {
                    if (i % 2 == 0) {
                        c10++;
                    } else {
                        c11++;
                    }
                }
            }

            if (abs(c00 + c01 - c10 - c11) >= 2) {
                return -1;
            }
            if (c00 + c01 == c10 + c11) {
                ret += min(c00, c01);
            }
            if (c00 + c01 > c10 + c11) {
                ret += c01;
            }
            if (c00 + c01 < c10 + c11) {
                ret += c11;
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (abs(board[0][0] - board[0][j]) !=
                        abs(board[i][0] - board[i][j])) {
                        return -1;
                    }
                }
            }
        }
        {
            // first col
            int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
            for (int i = 0; i < m; i++) {
                int num = board[i][0];
                if (num == 0) {
                    if (i % 2 == 0) {
                        c00++;
                    } else {
                        c01++;
                    }
                } else {
                    if (i % 2 == 0) {
                        c10++;
                    } else {
                        c11++;
                    }
                }
            }

            if (abs(c00 + c01 - c10 - c11) >= 2) {
                return -1;
            }
            if (c00 + c01 == c10 + c11) {
                ret += min(c00, c01);
            }
            if (c00 + c01 > c10 + c11) {
                ret += c01;
            }
            if (c00 + c01 < c10 + c11) {
                ret += c11;
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    if (abs(board[0][0] - board[i][0]) !=
                        abs(board[0][j] - board[i][j])) {
                        return -1;
                    }
                }
            }
        }

        return ret;
    }
};
}  // namespace leet
}  // namespace lst
