// Last updated: 3/18/2026, 10:41:05 AM
1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int count = 0;
7
8        for(int i = 0; i < m; i++) {
9            for(int j = 0; j < n; j++) {
10
11                if(i > 0) grid[i][j] += grid[i-1][j];
12                if(j > 0) grid[i][j] += grid[i][j-1];
13                if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1];
14
15                if(grid[i][j] <= k) count++;
16            }
17        }
18
19        return count;
20    }
21};