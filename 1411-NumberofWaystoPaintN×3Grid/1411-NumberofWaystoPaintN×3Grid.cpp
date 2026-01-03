// Last updated: 1/3/2026, 12:09:52 PM
1#define MOD 1000000007
2
3class Solution {
4public:
5    int numOfWays(int n) {
6        long long aba = 6, abc = 6;
7
8        for (int i = 2; i <= n; i++) {
9            long long newAba = (aba * 3 + abc * 2) % MOD;
10            long long newAbc = (aba * 2 + abc * 2) % MOD;
11            aba = newAba;
12            abc = newAbc;
13        }
14
15        return (aba + abc) % MOD;
16    }
17};
18