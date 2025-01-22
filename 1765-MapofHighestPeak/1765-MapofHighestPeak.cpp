class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));

        queue<vector<int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j] == 1){
                    q.push({i,j,0});
                    vis[i][j] = 1;
                }
            }
        }

        vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int r = temp[0];
            int c = temp[1];
            int h = temp[2];
            for(int i=0;i<4;i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr>=0 && nc>=0 && nr < m && nc < n && isWater[nr][nc] == 0 && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    q.push({nr,nc,h + 1});
                    ans[nr][nc] = h + 1;
                }
            }
        }
        return ans;
        
        
    }
};