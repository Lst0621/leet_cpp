#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    int maximumTop(const vector<int>& nums, int k) {
        int len = nums.size();
        if (k == 0) {
            return nums.front();
        }

        if (k == 1) {
            if (len == 1) {
                return -1;
            } else {
                return nums[1];
            }
        }

        if (len == 1) {
            return k % 2 == 0 ? nums.front() : -1;
        }

        if (k < len) {
            return max(*max_element(nums.begin(), nums.begin() + k - 1),
                       nums[k]);
        }
        if (k == len) {
            return *max_element(nums.begin(), nums.begin() + k - 1);
        }
        return *max_element(nums.begin(), nums.end());
    }
};
}  // namespace leet
}  // namespace lst
