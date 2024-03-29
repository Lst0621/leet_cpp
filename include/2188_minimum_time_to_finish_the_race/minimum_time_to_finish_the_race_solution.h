#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    int minimumFinishTime(const vector<vector<int>>& tires, int changeTime,
                          int numLaps) {
        auto trimmed = trim(tires);
        vector<pair<int, int>> round_ts =
            get_round_ts(trimmed, changeTime, numLaps);
        vector<int> cache(numLaps + 1, INT_MAX);
        return get_time(round_ts, cache, numLaps) - changeTime;
    }

   private:
    vector<vector<int>> trim(vector<vector<int>> tires) {
        sort(tires.begin(), tires.end());
        vector<vector<int>> ret;
        for (auto tire : tires) {
            if (!ret.empty() && ret.back()[0] == tire[0]) {
                continue;
            }
            ret.push_back(tire);
        }
        return ret;
    }

    int get_time(const vector<pair<int, int>>& round_ts, vector<int>& cache,
                 int round) {
        if (round <= 0) {
            return 0;
        }
        int& ret = cache[round];
        if (ret != INT_MAX) {
            return ret;
        }
        for (auto [r, ts] : round_ts) {
            long time = long(ts) + get_time(round_ts, cache, round - r);
            if (time < INT_MAX) {
                ret = min(ret, int(time));
            }
        }
        return ret;
    }

    vector<pair<int, int>> get_round_ts(const vector<vector<int>>& tires,
                                        int changeTime, int numLaps) {
        vector<pair<int, int>> round_ts_all;
        for (auto vec : tires) {
            long long f = vec[0];
            int r = vec[1];
            int round = 0;
            long long t = changeTime;
            while (true) {
                round++;
                t += f;
                if (t >= INT_MAX) {
                    break;
                }
                round_ts_all.emplace_back(round, t);
                if (round >= numLaps) {
                    break;
                }
                f *= r;
                if (f >= INT_MAX) {
                    break;
                }
            }
        }

        sort(round_ts_all.begin(), round_ts_all.end());
        vector<pair<int, int>> ret;
        for (auto round_ts : round_ts_all) {
            auto [round, ts] = round_ts;
            if (!ret.empty()) {
                auto prev = ret.back();
                if (round == prev.first) {
                    continue;
                }

                bool should_take = true;
                for (auto [prev_round, prev_ts] : ret) {
                    int fac = (round + prev_round - 1) / prev_round;
                    long opt_ts = long(fac) * prev_ts;
                    if (opt_ts <= ts) {
                        should_take = false;
                        break;
                    }
                }
                if (!should_take) {
                    continue;
                }
            }
            ret.push_back(round_ts);
        }
        return ret;
    }
};
}  // namespace leet
}  // namespace lst
