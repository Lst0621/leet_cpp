#include "all_include.h"

namespace lst {
namespace leet {
class Solution {
   public:
    string smallestSubsequence(const string& s, int k, char letter,
                               int repetition) {
        return smallestSubsequence_v3(s, k, letter, repetition);
    }

   private:
    string smallestSubsequence_v3(const string& s, int k, char letter,
                                  int repetition) {
        int len = int(s.size());
        string ret;
        int letter_count = 0;
        for (char c : s) {
            if (c == letter) {
                letter_count++;
            }
        }

        for (int i = 0; i < len; i++) {
            char c = s[i];
            while (!ret.empty() && c < ret.back() &&
                   int(ret.size()) - 1 + len - i >= k &&
                   repetition + (ret.back() == letter ? 1 : 0) <=
                       letter_count) {
                char back = ret.back();
                ret.pop_back();
                if (back == letter) {
                    repetition++;
                }
            }
            if (int(ret.size()) < k &&
                ((c == letter) || (k - int(ret.size()) - 1 >= repetition))) {
                ret += c;
                if (c == letter) {
                    repetition--;
                }
            }
            if (c == letter) {
                letter_count--;
            }
        }
        return ret;
    }

    string smallestSubsequence_v2(const string& s, int k, char letter,
                                  int repetition) {
        int l = s.size();
        int len = l;
        vector<int> cnt(l, 0);
        cnt.back() = s.back() == letter;
        for (int i = l - 2; i >= 0; i--) {
            cnt[i] = cnt[i + 1] + (s[i] == letter);
        }
        dp = vector<vector<vector<string>>>(
            len, vector<vector<string>>(
                     k + 1, vector<string>(repetition + 1, unknown)));
        return helper(s, 0, k, letter, repetition, cnt);
    }

    string& helper(const string& s, int pos, int k, char letter, int repetition,
                   const vector<int>& cnt) {
        if (k == 0) {
            return repetition > 0 ? impossible : empty;
        }
        if (pos == s.size()) {
            return impossible;
        }
        if (cnt[pos] < repetition) {
            return impossible;
        }

        string& ret = dp[pos][k][repetition];
        if (ret != unknown) {
            return ret;
        }
        string& take = helper(s, pos + 1, k - 1, letter,
                              max(0, repetition - (s[pos] == letter)), cnt);
        string& skip = helper(s, pos + 1, k, letter, repetition, cnt);
        if (take == impossible && skip == impossible) {
            ret = impossible;
            return ret;
        }
        if (take == impossible && skip != impossible) {
            ret = skip;
            return ret;
        }
        if (take != impossible && skip == impossible) {
            ret.reserve(take.size() + 1);
            ret = s[pos] + take;
            return ret;
        }
        ret = min(s[pos] + take, skip);
        return ret;
    }
    string impossible = "!";
    string unknown = "";
    string empty = "";
    vector<vector<vector<string>>> dp;

    string smallestSubsequence_v1(string s, int k, char letter,
                                  int repetition) {
        int l = s.size();
        int len = l;
        vector<int> cnt(l, 0);
        cnt.back() = s.back() == letter;
        for (int i = l - 2; i >= 0; i--) {
            cnt[i] = cnt[i + 1] + (s[i] == letter);
        }
        if (cnt.front() >= k && *min_element(s.begin(), s.end()) == letter) {
            string ret;
            for (int i = 0; i < k; i++) {
                ret += letter;
            }
            return ret;
        }

        using P = pair<string, int>;
        vector<P> candi;
        candi.emplace_back("", 0);
        for (int i = 0; i < len; i++) {
            cout << "round " << i << " " << s[i] << endl;
            vector<P> next;
            vector<int> from_orig;
            for (auto& p : candi) {
                string str = p.first;
                int c = p.second;

                if (str.size() + l - 1 - i >= k &&
                    c + ((i + 1 < len) ? cnt[i + 1] : 0) >= repetition &&
                    k - int(str.size()) >= repetition - c && str.size() <= k) {
                    next.emplace_back(str, c);
                    from_orig.push_back(1);
                }
                str = str + s[i];
                c += (s[i] == letter);

                if (str.size() + l - 1 - i >= k &&
                    c + ((i + 1 < len) ? cnt[i + 1] : 0) >= repetition &&
                    k - int(str.size()) >= repetition - c && str.size() <= k) {
                    next.emplace_back(str, c);
                    from_orig.push_back(0);
                }
            }
            int n = next.size();
            vector<int> remove(n);
            for (int i = 0; i < n; i++) {
                string& s1 = next[i].first;
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (from_orig[i] == 1 && from_orig[j] == 1) {
                        continue;
                    }

                    string& s2 = next[j].first;
                    if ((s1 > s2 && !start(s1, s2)) || (s1 == s2 && i < j)) {
                        remove[i] = 1;
                        break;
                    }
                }
            }
            candi.clear();
            int max_size = 0;
            for (int i = 0; i < n; i++) {
                if (!remove[i]) {
                    max_size = max(max_size, int(next[i].first.size()));
                    candi.push_back(move(next[i]));
                }
            }
            sort(candi.begin(), candi.end(), greater<>());
            cout << candi.front().first << "||" << candi.back().first << endl;
        }
        return candi[0].first;
    }
    bool start(string& s1, string& s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        if (l1 < l2) {
            return false;
        }
        for (int i = 0; i < l2; i++) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }
};
}  // namespace leet
}  // namespace lst
