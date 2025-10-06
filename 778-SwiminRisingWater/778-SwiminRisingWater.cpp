// Last updated: 10/6/2025, 9:48:02 AM
class Solution {
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};

    bool fun(int maxTime, vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            // ✅ Fixed boundary check
            if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid.size() &&
                vis[nr][nc] != 1 && grid[nr][nc] <= maxTime) {
                fun(maxTime, grid, vis, nr, nc);
            }
        }
        return vis[grid.size() - 1][grid.size() - 1];
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0;
        int high = n * n;

        int ans = -1;
        // ✅ Moved vis initialization inside loop
        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<vector<int>> vis(n, vector<int>(n, 0)); // new vis each iteration

            // ✅ Start DFS only if start cell is accessible
            if (grid[0][0] <= mid && fun(mid, grid, vis, 0, 0)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
