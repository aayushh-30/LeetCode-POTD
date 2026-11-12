// Last updated: 11/12/2026, 10:29:59 PM
1class Solution {
2    int helper(vector<vector<int>>& grid,queue<vector<int>> &q,int m,int n){
3        vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
4        int t = 0;
5        while(!q.empty()){
6            auto temp = q.front();
7            q.pop();
8            int r = temp[0];
9            int c = temp[1];
10            t = temp[2];
11
12            for(int i=0;i<4;i++){
13                int nr = r + dir[i][0];
14                int nc = c + dir[i][1];
15
16                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1){
17                    grid[nr][nc] = 2;
18                    q.push({nr,nc,t+1});
19                }
20            }
21        }
22        return t;
23    }
24public:
25    int orangesRotting(vector<vector<int>>& grid) {
26        int m = grid.size();
27        int n = grid[0].size();
28
29        queue<vector<int>> q;
30        for(int i=0;i<m;i++){
31            for(int j=0;j<n;j++){
32                if(grid[i][j] == 2){
33                    q.push({i,j,0});
34                }
35            }
36        }
37
38        int ans = helper(grid,q,m,n);
39
40        for(int i=0;i<m;i++){
41            for(int j=0;j<n;j++){
42                if(grid[i][j] == 1){
43                    ans = -1;
44                }
45            }
46        }
47
48        return ans;
49
50
51        
52    }
53};