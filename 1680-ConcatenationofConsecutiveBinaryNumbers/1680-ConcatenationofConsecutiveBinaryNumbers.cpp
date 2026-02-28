// Last updated: 2/28/2026, 11:00:32 AM
1class Solution {
2public:
3    int concatenatedBinary(int n) {
4        long long ans = 0;
5        const int mod = 1e9 + 7;
6        int bitLength = 0;
7
8        for (int i = 1; i <= n; i++) {
9            
10            if ((i & (i - 1)) == 0) {
11                bitLength++;
12            }
13
14            ans = ((ans << bitLength) | i) % mod;
15        }
16
17        return ans;
18    }
19};