#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret;
        for (int& num : nums) {
            num--;
        }
        for (int i = 0; i < len; i++) {
            int num = nums[i];
            if (nums[i] == i) {
                continue;
            }
            nums[i] = INT_MAX;
            while (true) {
                if (nums[num] == num) {
                    ret.push_back(num + 1);
                    break;
                }
                int next = nums[num];
                nums[num] = num;
                num = next;
                if (next == INT_MAX) {
                    break;
                }
            }
        }

        return ret;
    }
};

}  // namespace leet
}  // namespace lst
