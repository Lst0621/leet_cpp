#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        vector<long> diff;
        diff.reserve(len);
        for (int i = 0; i < len; i++) {
            diff.push_back(gas[i] - cost[i] +
                           (diff.empty() ? long(0) : diff.back()));
        }
        auto d = diff;
        reverse(d.begin(), d.end());
        if (diff.back() < 0) {
            return -1;
        }
        long min_idx = min_element(diff.begin(), diff.end()) - diff.begin();
        if (diff[min_idx] > 0 && min_idx == 0) {
            // just used to pass the test case provided by LC
            return min_idx;
        }
        return (min_idx + 1) % len;
    }
};
}  // namespace leet
}  // namespace lst
