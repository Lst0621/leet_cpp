#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    vector<string> addOperators(string num, int target) {
        if (target < 0 && to_string(target).size() - 1 == num.size()) {
            return {};
        }
        string s;
        s += num[0];
        vector<long> stk;
        stk.push_back(1);
        stk.push_back(num[0] - '0');
        return helper(num, s, 0, 1, stk, target);
    }

   private:
    long get_product(const vector<long>& stk) {
        long ret = 1;
        for (long num : stk) {
            ret *= num;
        }
        return ret;
    }

    void add_to_vector(vector<string>& ret, const vector<string>& added) {
        ret.insert(ret.end(), added.begin(), added.end());
    }
    vector<string> helper(string& num, string& s, long sum, int pos,
                          vector<long>& stk, long target) {
        vector<string> ret;
        if (pos == num.size()) {
            if (sum + get_product(stk) == target) {
                ret.push_back(s);
            }
            return ret;
        }

        int m = num[pos] - '0';
        vector<long> next_stk;
        const long next_sum = sum + get_product(stk);
        // +
        s += '+';
        s += num[pos];
        next_stk.push_back(1);
        next_stk.push_back(m);

        add_to_vector(ret, helper(num, s, next_sum, pos + 1, next_stk, target));
        s.pop_back();
        s.pop_back();
        next_stk.clear();
        // -
        s += '-';
        s += num[pos];
        next_stk.push_back(-1);
        next_stk.push_back(m);
        add_to_vector(ret, helper(num, s, next_sum, pos + 1, next_stk, target));
        s.pop_back();
        s.pop_back();
        next_stk.clear();
        // *
        s += '*';
        s += num[pos];
        stk.push_back(m);
        add_to_vector(ret, helper(num, s, sum, pos + 1, stk, target));
        s.pop_back();
        s.pop_back();
        stk.pop_back();
        // no op
        if (stk.back() != 0) {
            s += num[pos];
            stk.back() = stk.back() * 10 + m;
            add_to_vector(ret, helper(num, s, sum, pos + 1, stk, target));
            s.pop_back();
            stk.back() /= 10;
        }

        return ret;
    }
};
}  // namespace leet
}  // namespace lst
