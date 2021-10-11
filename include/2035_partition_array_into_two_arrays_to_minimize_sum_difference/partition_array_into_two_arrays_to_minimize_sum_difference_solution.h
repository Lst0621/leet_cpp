#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    using SetType = unordered_set<int>;
    // using SetType = set<int>;
    int minimumDifference(const vector<int>& nums) {
        int n = nums.size() / 2;
        vector<SetType> sums1(n + 1), sums2(n + 1);
        sums1[0].insert(0);
        sums2[0].insert(0);
        record_sum(nums, 0, n, sums1);
        record_sum(nums, n, 2 * n, sums2);
        int sum_all = accumulate(nums.begin(), nums.end(), 0);
        int ret = INT_MAX;
        for (int i = 0; i <= n; i++) {
            auto& s1 = sums1[i];
            auto& s2 = sums2[n - i];
            vector<int> v1(s1.begin(), s1.end());
            vector<int> v2(s2.begin(), s2.end());
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            int l1 = v1.size();
            int l2 = v2.size();
            int idx1 = 0, idx2 = l2 - 1;
            for (; idx1 < l1; idx1++) {
                while (idx2 >= 0) {
                    int sum = v1[idx1] + v2[idx2];
                    int another = sum_all - sum;
                    int diff = abs(sum - another);
                    ret = min(ret, diff);
                    if (sum < another) {
                        break;
                    }
                    idx2--;
                }
            }
        }
        return ret;
    }

    void record_sum(const vector<int>& nums, int start, int end,
                    vector<SetType>& sums) {
        for (int pos = 0; start + pos < end; pos++) {
            // cout<<pos<<endl;
            for (int cnt = pos; cnt >= 0; cnt--) {
                for (int sum : sums[cnt]) {
                    // cout<<cnt<<" "<<sum<<"| insert "<<cnt+1<<"
                    // "<<sum+nums[start+pos]<<" " <<sums[cnt+1].size();
                    sums[cnt + 1].insert(sum + nums[start + pos]);
                    // cout<<" " <<sums[cnt+1].size()<<endl;
                }
            }
        }
    }
};
}  // namespace leet
}  // namespace lst
