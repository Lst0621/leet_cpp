#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> m;
        const int s = nums.size();
        for (int i = 0; i < s; i++) {
            const int& num = nums[i];
            const int another = target - num;
            if (m.count(another)) {
                return {m.at(another), i};
            }
            m[num] = i;
        }
        return {-1, -1};
    }
};
}  // namespace leet
}  // namespace lst
