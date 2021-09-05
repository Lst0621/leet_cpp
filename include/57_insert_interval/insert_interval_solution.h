#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    vector<vector<int>> insert(const vector<vector<int>>& intervals,
                               const vector<int>& newInterval) {
        map<int, int> m;
        for (auto& vec : intervals) {
            const int start = vec[0];
            const int end = vec[1];
            m[start]++;
            m[end]--;
        }
        m[newInterval[0]]++;
        m[newInterval[1]]--;

        int sum = 0;
        vector<vector<int>> ret;
        int begin = -1;
        bool started = false;
        for (auto kv : m) {
            sum += kv.second;
            if (sum > 0 && !started) {
                started = true;
                begin = kv.first;
            }
            if (sum == 0) {
                started = false;
                ret.push_back({kv.second == 0 ? kv.first : begin, kv.first});
            }
        }
        return ret;
    }
};
}  // namespace leet
}  // namespace lst
