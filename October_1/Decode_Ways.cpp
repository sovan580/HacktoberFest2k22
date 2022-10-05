class Solution {
    public:
        int decode(const vector<int>& cs, int i, int n, vector<int>& memo) {
            if (memo[i] != -1) {
                return memo[i];
            }
            int ways = 0;
            if (cs[i] > 0 && cs[i] <= 2 && (i < n - 1) && (cs[i+1] <= 6 || cs[i] == 1)) {
                ways += decode(cs, i + 2, n, memo);
            }
            if (cs[i] != 0) {
                ways += decode(cs, i + 1, n, memo);
            }
            memo[i] = ways;
            return ways;
        }

        int numDecodings(string s) {
            if (s[0] == '0') {
                return 0;
            }
            int n = s.size();
            vector<int> memo(n + 1, - 1);
            memo[n] = 1;
            vector<int> cs;
            cs.resize(n);
            for (int i = 0; i < s.size(); i++) {
                cs[i] = s[i] - '0';
            }
            return decode(cs, 0, cs.size(), memo);
        }
};
