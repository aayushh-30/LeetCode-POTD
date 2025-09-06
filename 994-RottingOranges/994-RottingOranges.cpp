// Last updated: 9/6/2025, 9:34:11 AM
class Solution {
    int fun(vector<vector<int>>& grid,vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    // if rotten push into the queue;
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int time = -1;
        while(!q.empty()){
            int nk = q.size();
            time++;
            while(nk--){
                
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int newRow = row + dir[i].first;
                    int newCol = col + dir[i].second;

                    if(newRow >= 0 && newRow<m && newCol>=0 && newCol < n && vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1){
                        vis[newRow][newCol] = 1;
                        q.push({newRow,newCol});
                        grid[newRow][newCol] = 2;
                    }
                }
            }
        }
        return time;
        
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        int minTime = fun(grid,vis);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return minTime == -1 ? 0 : minTime;
        
    }
};