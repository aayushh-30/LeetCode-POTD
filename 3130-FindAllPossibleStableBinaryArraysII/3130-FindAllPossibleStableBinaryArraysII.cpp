// Last updated: 3/11/2026, 12:29:23 AM
1class Solution {
2public:
3    int numberOfStableArrays(int zero, int one, int limit) {
4        int mod = 1e9 + 7;
5        vector<vector<vector<int>>> memo(
6            zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));
7
8        function<int(int, int, int)> dp = [&](int zero, int one,
9                                              int lastBit) -> int {
10            if (zero == 0) {
11                return (lastBit == 0 || one > limit) ? 0 : 1;
12            } else if (one == 0) {
13                return (lastBit == 1 || zero > limit) ? 0 : 1;
14            }
15
16            if (memo[zero][one][lastBit] == -1) {
17                int res = 0;
18                if (lastBit == 0) {
19                    res = (dp(zero - 1, one, 0) + dp(zero - 1, one, 1)) % mod;
20                    if (zero > limit) {
21                        res = (res - dp(zero - limit - 1, one, 1) + mod) % mod;
22                    }
23                } else {
24                    res = (dp(zero, one - 1, 0) + dp(zero, one - 1, 1)) % mod;
25                    if (one > limit) {
26                        res = (res - dp(zero, one - limit - 1, 0) + mod) % mod;
27                    }
28                }
29                memo[zero][one][lastBit] = res % mod;
30            }
31            return memo[zero][one][lastBit];
32        };
33
34        return (dp(zero, one, 0) + dp(zero, one, 1)) % mod;
35    }
36};