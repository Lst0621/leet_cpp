#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int correct = get_correct(s);
        auto& all_results = get_all(s);
        int ret = 0;
        for (int num : answers) {
            if (num == correct) {
                ret += R1;
                continue;
            }
            if (all_results.count(num)) {
                ret += R2;
            }
        }
        return ret;
    }

   private:
    map<string, unordered_set<int>> cache;
    static constexpr int LIMIT = 1000;
    static constexpr int R1 = 5;
    static constexpr int R2 = 2;
    unordered_set<int>& get_all(string& s) {
        if (cache.count(s)) {
            return cache.at(s);
        }

        vector<int> splits;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '*') {
                splits.push_back(i);
            }
        }
        if (splits.empty()) {
            int ret = atoi(s.c_str());
            if (ret <= LIMIT) {
                cache[s] = {ret};

            } else {
                cache[s] = {};
            }
            return cache.at(s);
        }
        // 1+2+3+4
        unordered_set<int> ret;
        for (int i = 0; i < splits.size(); i++) {
            int idx = splits[i];
            string left = s.substr(0, idx);
            string right = s.substr(idx + 1, s.size() - idx - 1);
            auto left_set = get_all(left);
            auto right_set = get_all(right);
            for (int l : left_set) {
                for (int r : right_set) {
                    int num = (s[idx] == '+') ? l + r : l * r;
                    if (num <= LIMIT) {
                        ret.insert(num);
                    }
                }
            }
        }
        cache[s] = move(ret);
        return cache.at(s);
    }

    static int get_correct(string& s) {
        if (s.size() == 1) {
            return s[0] - '0';
        }

        vector<int> vec;
        vec.push_back(s[0] - '0');
        int len = s.size();
        for (int i = 1; i < len; i += 2) {
            int num = s[i + 1] - '0';
            if (s[i] == '+') {
                vec.push_back(num);
            } else {
                vec.back() *= num;
            }
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};
}  // namespace leet
}  // namespace lst
