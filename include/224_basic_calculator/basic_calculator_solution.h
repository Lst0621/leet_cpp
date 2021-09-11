#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    int calculate(string s) {
        int sum = 0;
        int num = 0;
        int sign_current = 1;
        int sign_global = 1;
        vector<int> signs;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
                continue;
            }
            if (c == ' ') {
                sum += sign_global * sign_current * num;
                num = 0;
                continue;
            }
            if (c == '+') {
                sum += sign_global * sign_current * num;
                num = 0;
                sign_current = 1;
                continue;
            }
            if (c == '-') {
                sum += sign_global * sign_current * num;
                num = 0;
                sign_current = -1;
                continue;
            }
            if (c == '(') {
                sum += sign_global * sign_current * num;
                num = 0;
                signs.push_back(sign_current);
                sign_global *= signs.back();
                sign_current = 1;
                continue;
            }
            if (c == ')') {
                sum += sign_global * sign_current * num;
                num = 0;
                sign_global *= signs.back();
                signs.pop_back();
                sign_current = 1;
                continue;
            }
        }
        sum += sign_current * num;
        return sum;
    }
};
}  // namespace leet
}  // namespace lst
