#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    bool possiblyEquals(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        DP_TYPE dp(l1 + 1,
                   vector<vector<int>>(l2 + 1, vector<int>(2002, UNKNOWN)));
        return can_match(s1, s2, dp, l1, l2);
    }

   private:
    using DP_TYPE = vector<vector<vector<int>>>;
    static constexpr const int UNKNOWN = -1;
    static constexpr const int MATCH = 1;
    static constexpr const int NOT_MATCH = 0;
    static constexpr const int SHIFT = 1000;

    bool can_match(string& s1, string& s2, DP_TYPE& dp, int len1, int len2,
                   int offset = 0) {
        if (len1 == 0 && len2 == 0) {
            return offset == 0;
        }
        if (len1 < 0 || len2 < 0) {
            return false;
        }

        int& ans = dp[len1][len2][offset + SHIFT];
        if (ans != UNKNOWN) {
            return ans;
        }
        LOG(INFO) << "[" << s1.substr(0, len1) << "] [" << s2.substr(0, len2)
                  << "] " << offset << endl;

        if (offset > 0) {
            if (len1 == 0) {
                return false;
            }
            int idx = len1 - 1;
            if (isalpha(s1[idx])) {
                ans = can_match(s1, s2, dp, len1 - 1, len2, offset - 1);
                return ans;
            }
            int num = 0;
            int weight = 1;
            int width = 1;
            while (idx >= 0 && isdigit(s1[idx]) && weight <= 100) {
                num = num + (s1[idx] - '0') * weight;
                weight *= 10;
                idx--;
                if (can_match(s1, s2, dp, len1 - width, len2, offset - num)) {
                    ans = MATCH;
                    return ans;
                }
                width++;
            }
            ans = NOT_MATCH;
            return ans;
        }

        if (offset < 0) {
            if (len2 == 0) {
                return false;
            }
            int idx = len2 - 1;
            if (isalpha(s2[idx])) {
                ans = can_match(s1, s2, dp, len1, len2 - 1, offset + 1);
                return ans;
            }
            int num = 0;
            int weight = 1;
            int width = 1;
            while (idx >= 0 && isdigit(s2[idx]) && weight <= 100) {
                num = num + (s2[idx] - '0') * weight;
                weight *= 10;
                idx--;
                if (can_match(s1, s2, dp, len1, len2 - width, offset + num)) {
                    ans = MATCH;
                    return ans;
                }
                width++;
            }
            ans = NOT_MATCH;
            return ans;
        }
        if (len1 == 0 || len2 == 0) {
            return false;
        }
        char c1 = s1[len1 - 1];
        char c2 = s2[len2 - 1];
        if (isalpha(c1) && isalpha(c2)) {
            ans = c1 == c2 && can_match(s1, s2, dp, len1 - 1, len2 - 1);
            return ans;
        }

        // c1 alpha c2 number
        if (isalpha(c1)) {
            int number = 0;
            int weight = 1;
            for (int i = 1; i <= 3; i++) {
                if (len2 - i < 0 || isalpha(s2[len2 - i])) {
                    ans = NOT_MATCH;
                    return ans;
                }
                number += (s2[len2 - i] - '0') * weight;
                weight *= 10;
                if (can_match(s1, s2, dp, len1 - 1, len2 - i, number - 1)) {
                    ans = MATCH;
                    return ans;
                }
            }
        }

        // c2 alpha c1 number
        if (isalpha(c2)) {
            int number = 0;
            int weight = 1;
            for (int i = 1; i <= 3; i++) {
                if (len1 - i < 0 || isalpha(s1[len1 - i])) {
                    ans = NOT_MATCH;
                    return ans;
                }
                number += (s1[len1 - i] - '0') * weight;
                weight *= 10;
                if (can_match(s1, s2, dp, len1 - i, len2 - 1, 1 - number)) {
                    ans = MATCH;
                    return ans;
                }
            }
        }

        // both digit
        int number1 = 0;
        int weight1 = 1;
        for (int i = 1; i <= 3; i++) {
            if (len1 - i < 0 || isalpha(s1[len1 - i])) {
                ans = NOT_MATCH;
                return ans;
            }
            number1 += (s1[len1 - i] - '0') * weight1;
            weight1 *= 10;
            int number2 = 0;
            int weight2 = 1;
            for (int j = 1; j <= 3; j++) {
                if (len2 - j < 0 || isalpha(s2[len2 - j])) {
                    break;
                }
                number2 += (s2[len2 - j] - '0') * weight2;
                weight2 *= 10;
                if (can_match(s1, s2, dp, len1 - i, len2 - j,
                              number2 - number1)) {
                    ans = MATCH;
                    return ans;
                }
            }
        }
        ans = NOT_MATCH;
        return ans;
    }
};
}  // namespace leet
}  // namespace lst
