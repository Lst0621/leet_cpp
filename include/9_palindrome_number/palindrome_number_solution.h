#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }

        vector<int> v;
        v.reserve(32);
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }
        int num = v.size();
        for (int i = 0; i <= num / 2; i++) {
            if (v[i] != v[num - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
}  // namespace leet
}  // namespace lst
