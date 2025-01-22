class Solution {
    int m,n;
    int fun(vector<vector<int>>& grid,int r,int c,vector<vector<int>> &vis){
        queue<vector<int>> q;
        q.push({r,c,grid[r][c]});
        vis[r][c] = 1;
        vector<pair<int,int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
        int totalFish = 0;
        while(!q.empty()){
            auto temp = q.front();
            int row = temp[0];
            int col = temp[1];
            int fish = temp[2];
            q.pop();
            totalFish += fish;

            for(int i=0;i<4;i++){
                int newRow = row + dirs[i].first;
                int newCol = col + dirs[i].second;

                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && vis[newRow][newCol]==0 && grid[newRow][newCol]>0){
                    vis[newRow][newCol] = 1;
                    q.push({newRow,newCol,grid[newRow][newCol]});
                }
            }


        }

        return totalFish;


    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]>0){
                    ans = max(ans,fun(grid,i,j,vis));
                }
            }
        }

        return ans;

        

        
    }
};