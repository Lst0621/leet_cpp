#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    long reverse_helper(int x) {
        long ret = 0;
        while (x) {
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret > INT_MAX ? 0 : ret;
    }
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }

        if (x == INT_MIN) {
            return 0;
        }

        if (x < 0) {
            return -reverse(-x);
        }
        return reverse_helper(x);
    }
};
}  // namespace leet
}  // namespace lst
