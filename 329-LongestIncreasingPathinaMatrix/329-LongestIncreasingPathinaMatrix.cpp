// Last updated: 4/27/2025, 11:53:39 AM
class Solution {
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int fun(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {r, c}});
        int ans = INT_MIN;

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int pv = grid[temp.second.first][temp.second.second];
            int dist = temp.first;
            ans = max(ans, dist);

            for (int i = 0; i < 4; i++) {
                int nr = temp.second.first + dir[i][0];
                int nc = temp.second.second + dir[i][1];

                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] > pv) {
                    q.push({dist + 1, {nr, nc}});
                }
            }
        }

        return ans;
    }

    vector<vector<int>> dp;
    int fun2(vector<vector<int>> &grid, int r, int c) {

        int dist = 1;
        if (dp[r][c] != -1)
            return dp[r][c];
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            int pv = grid[r][c];

            if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() &&
                grid[nr][nc] > pv) {
                dist = max(dist, 1 + fun2(grid, nr, nc));
            }
        }

        return dp[r][c] = dist;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int ans = 0;
        dp.resize(205, vector<int>(205, -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int res = fun2(grid, i, j);
                ans = max(ans, res);
            }
        }

        return ans;
    }
};