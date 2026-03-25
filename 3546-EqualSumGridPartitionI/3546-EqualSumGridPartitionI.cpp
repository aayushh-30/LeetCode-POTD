// Last updated: 3/25/2026, 8:46:58 AM
1class Solution {
2    bool canPart(vector<long long>& arr) {
3        long long total = accumulate(arr.begin(), arr.end(), 0LL);
4        long long currSum = 0;
5        for (int i = 0; i < arr.size(); i++) {
6            currSum += arr[i];
7            if (2 * currSum * 1LL == total) {
8                return true;
9            }
10        }
11        return false;
12    }
13
14public:
15    bool canPartitionGrid(vector<vector<int>>& grid) {
16        int m = grid.size();
17        int n = grid[0].size();
18        vector<long long> row(m, 0), col(n, 0);
19        for (int i = 0; i < m; i++) {
20            for (int j = 0; j < n; j++) {
21                row[i] += grid[i][j];
22                col[j] += grid[i][j];
23            }
24        }
25
26        return canPart(row) || canPart(col);
27    }
28};