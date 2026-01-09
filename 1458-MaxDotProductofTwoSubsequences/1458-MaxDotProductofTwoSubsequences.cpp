// Last updated: 1/10/2026, 12:24:08 AM
1class Solution {
2public:
3    vector<int> nums1, nums2;
4    vector<vector<int>> memo;
5    int n, m;
6    const int NEG_INF = -1e9;
7
8    int dp(int i, int j) {
9        if (i == n || j == m)
10            return NEG_INF;
11
12        if (memo[i][j] != INT_MIN)
13            return memo[i][j];
14
15        int take = nums1[i] * nums2[j];
16
17        int res = max({
18            take + dp(i + 1, j + 1), // take both and continue
19            take,                   // take and end here
20            dp(i + 1, j),            // skip nums1[i]
21            dp(i, j + 1)             // skip nums2[j]
22        });
23
24        return memo[i][j] = res;
25    }
26
27    int maxDotProduct(vector<int>& a, vector<int>& b) {
28        nums1 = a;
29        nums2 = b;
30        n = nums1.size();
31        m = nums2.size();
32
33        memo.assign(n, vector<int>(m, INT_MIN));
34        return dp(0, 0);
35    }
36};