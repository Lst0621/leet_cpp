#include "all_include.h"

namespace lst {
namespace leet {
class UF {
   public:
    UF(int s) {
        for (int i = 0; i < s; i++) {
            groups.push_back(i);
        }
    }
    int get_group(int n) {
        int group = groups[n];
        if (group == n) {
            return group;
        }
        int ret = get_group(group);
        groups[n] = ret;
        return ret;
    }
    void unite(int a, int b) {
        int g_a = get_group(a);
        int g_b = get_group(b);
        if (g_a == g_b) {
            return;
        }
        groups[a] = g_b;
        groups[g_a] = g_b;
    }

   private:
    vector<int> groups;
};
class Solution {
   public:
    int largestComponentSize(const vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());
        UF uf(max_num + 1);
        for (int num : nums) {
            // cout<<num<<" | ";
            const auto facs = get_prime_factors(num);
            for (int fac : facs) {
                // cout<<fac<<" ";
                uf.unite(num, fac);
            }
            // cout<<endl;
        }
        unordered_map<int, int> group_cnt;
        int ret = 1;
        for (int num : nums) {
            int group = uf.get_group(num);
            group_cnt[group]++;
            ret = max(ret, group_cnt[group]);
        }
        return ret;
    }

    vector<int> get_prime_factors(int num) {
        vector<int> ret;
        for (int fac = 2; fac * fac <= num; fac++) {
            if (num % fac != 0) {
                continue;
            }
            ret.push_back(fac);
            while (num % fac == 0) {
                num /= fac;
            }
        }
        if (num != 1) {
            ret.push_back(num);
        }
        return ret;
    }
};
}  // namespace leet
}  // namespace lst
