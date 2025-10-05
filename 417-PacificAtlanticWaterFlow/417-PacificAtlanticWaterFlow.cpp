// Last updated: 10/5/2025, 3:08:13 PM
class Solution {
    int m, n;
    vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& ocean, vector<vector<int>>& heights) {
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && 
                    heights[nr][nc] >= heights[r][c] && ocean[nr][nc] == 0) {
                    ocean[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty()) return {};

        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        queue<pair<int, int>> pacificQueue, atlanticQueue;

        for (int i = 0; i < m; i++) {
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, n - 1});
            pacific[i][0] = 1;
            atlantic[i][n - 1] = 1;
        }
        for (int i = 0; i < n; i++) {
            pacificQueue.push({0, i});
            atlanticQueue.push({m - 1, i});
            pacific[0][i] = 1;
            atlantic[m - 1][i] = 1;
        }

        bfs(pacificQueue, pacific, heights);
        bfs(atlanticQueue, atlantic, heights);


        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
