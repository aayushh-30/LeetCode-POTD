// Last updated: 11/12/2026, 9:55:38 PM
1class Solution {
2    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
3    void helper(vector<vector<char>>& grid, vector<vector<int>>& vis,int r,int c,int m, int n){
4        queue<pair<int,int>> q;
5        q.push({r,c});
6        vis[r][c] = 1;
7
8        while(!q.empty()){
9            auto temp = q.front();
10            q.pop();
11            int row = temp.first;
12            int col = temp.second;
13
14            for(int i=0;i<4;i++){
15                int nr = row + dir[i].first;
16                int nc = col + dir[i].second;
17
18                if(nr >=0 && nc >=0 && nr < m && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == '1'){
19                    q.push({nr,nc});
20                    vis[nr][nc] = 1;
21                }
22            }
23
24        }
25
26    }
27public:
28    int numIslands(vector<vector<char>>& grid) {
29        int m = grid.size();
30        int n = grid[0].size();
31
32        vector<vector<int>> vis(m,vector<int>(n,0));
33        int ans = 0;
34        for(int i=0;i<m;i++){
35            for(int j=0;j<n;j++){
36                if(vis[i][j]!=1 && grid[i][j] == '1'){
37                    helper(grid,vis,i,j,m,n);
38                    ans++;
39                }
40            }
41        }
42
43        return ans;
44        
45    }
46};