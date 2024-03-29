#include "all_include.h"

namespace lst {
namespace leet {
// https://leetcode.com/problems/count-array-pairs-divisible-by-k/
class Solution {
   public:
    // adding const to signature so that tests are easier to write.
    long long countPairs(const vector<int>& nums, int k) {
        unordered_map<long long, long long> res_cnt;
        for (int num : nums) {
            res_cnt[num % k]++;
        }

        long long ret = 0;
        const long long total_number = nums.size();
        for (auto const [num1, count1] : res_cnt) {
            if (num1 == 0) {
                // numbers in this bucket are already multiple of k,
                // thus any multiple of these numbers are also multiple of k.
                // (num1 is multiple of k while num2 is not) + (both num1 and
                // num2 are multiple of k)
                ret += count1 * (total_number - count1) +
                       count1 * (count1 - 1) / 2;
                continue;
            }

            // smallest num2 so that num1 * num2 % k == 0, when num1 is fixed
            const long long num2_min = lcm(num1, (long long)(k)) / num1;
            for (long long num2 = num2_min; num2 < k; num2 += num2_min) {
                if (num2 < num1) {
                    continue;
                }

                if (num2 == num1) {
                    ret += count1 * (count1 - 1) / 2;
                    continue;
                }

                if (res_cnt.count(num2) == 0) {
                    continue;
                }

                ret += count1 * res_cnt.at(num2);
            }
        }

        return ret;
    }
};
}  // namespace leet
}  // namespace lst
