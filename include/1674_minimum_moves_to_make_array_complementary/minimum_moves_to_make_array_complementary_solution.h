#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    int minMoves(const vector<int>& nums, const int limit) {
        return minMoves3(nums, limit);
    }

    struct Bar {
        int start;
        int end;
        int cost;
    };

    int minMoves3(const vector<int>& nums, const int limit) {
        const int size = nums.size();
        vector<int> costs(2 * limit + 1);
        for (int i = 0; i < size / 2; i++) {
            const int a = nums[i];
            const int b = nums[size - 1 - i];
            const int lower = min(a, b) + 1;
            const int upper = max(a, b) + limit;
            const int sum = a + b;
            vector<Bar> bars = {{2, lower - 1, 2},
                                {lower, sum - 1, 1},
                                {sum, sum, 0},
                                {sum + 1, upper, 1},
                                {upper + 1, 2 * limit, 2}};
            // [2,lower -1]: 2
            // [lower, sum-1]: 1
            // [sum]: 0
            // [sum+1, upper]: 1
            // [upper+1,2 * limit]: 2

            bool first = true;
            for (int i = 0; i < bars.size(); i++) {
                const Bar& bar = bars.at(i);
                if (bar.end < bar.start) {
                    continue;
                }
                if (bar.start > 2 * limit) {
                    continue;
                }
                int cost = first ? bar.cost : bar.cost - bars.at(i - 1).cost;
                costs[bar.start] += cost;
                first = false;
            }
        }
        int ret = INT_MAX;
        int cost = 0;
        for (int i = 2; i < costs.size(); i++) {
            cost += costs[i];
            ret = min(ret, cost);
        }

        return ret;
    }

    int minMoves2(const vector<int>& nums, const int limit) {
        const int size = nums.size();
        map<int, int> costs;
        for (int i = 0; i < size / 2; i++) {
            const int a = nums[i];
            const int b = nums[size - 1 - i];
            const int lower = min(a, b) + 1;
            const int upper = max(a, b) + limit;
            const int sum = a + b;
            vector<Bar> bars = {{2, lower - 1, 2},
                                {lower, sum - 1, 1},
                                {sum, sum, 0},
                                {sum + 1, upper, 1},
                                {upper + 1, 2 * limit, 2}};
            // [2,lower -1]: 2
            // [lower, sum-1]: 1
            // [sum]: 0
            // [sum+1, upper]: 1
            // [upper+1,2 * limit]: 2

            bool first = true;
            for (int i = 0; i < bars.size(); i++) {
                const Bar& bar = bars.at(i);
                if (bar.end < bar.start) {
                    continue;
                }
                if (bar.start > 2 * limit) {
                    continue;
                }
                int cost = first ? bar.cost : bar.cost - bars.at(i - 1).cost;
                costs[bar.start] += cost;
                first = false;
            }
        }
        int ret = INT_MAX;
        int cost = 0;
        for (const auto& kv : costs) {
            cost += kv.second;
            ret = min(ret, cost);
        }
        return ret;
    }

    int minMoves1(const vector<int>& nums, const int limit) {
        const int size = nums.size();
        vector<int> v(2 * limit + 1);
        for (int i = 0; i < size / 2; i++) {
            const int a = nums[i];
            const int b = nums[size - 1 - i];
            const int lower = min(a, b) + 1;
            const int upper = max(a, b) + limit;
            const int sum = a + b;

            // [2,lower -1]: 2
            // [lower, sum-1]: 1
            // [sum]: 0
            // [sum+1, upper]: 1
            // [upper+1,2 * limit]: 2

            fill(v, 2, lower - 1, 2);
            fill(v, lower, sum - 1, 1);
            fill(v, sum + 1, upper, 1);
            fill(v, upper + 1, 2 * limit, 2);
        }
        int ret = v[2];
        for (int i = 3; i < v.size() - 1; i++) {
            ret = min(ret, v[i]);
        }
        return ret;
    }

   private:
    void fill(vector<int>& v, const int start, const int end, const int num) {
        for (int i = start; i <= end; i++) {
            v[i] += num;
        }
    }
};
}  // namespace leet
}  // namespace lst
