// Last updated: 3/27/2026, 10:56:50 PM
1class Solution {
2public:
3    bool areSimilar(vector<vector<int>>& mat, int k) {
4        int m = mat.size(), n = mat[0].size();
5        k %= n;
6
7        for (int i = 0; i < m; i++) {
8            for (int j = 0; j < n; j++) {
9                if (mat[i][j] != mat[i][(j + k) % n]) {
10                    return false;
11                }
12            }
13        }
14        return true;
15    }
16};