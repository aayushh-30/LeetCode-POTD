// Last updated: 1/28/2026, 12:55:11 PM
1class Solution {
2    int fun(vector<vector<int>>& grid,vector<vector<int>>& vis){
3        int m = grid.size();
4        int n = grid[0].size();
5        vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
6        queue<pair<int,int>> q;
7        for(int i=0;i<m;i++){
8            for(int j=0;j<n;j++){
9                if(grid[i][j] == 2){
10                    // if rotten push into the queue;
11                    q.push({i,j});
12                }
13            }
14        }
15        int time = -1;
16        while(!q.empty()){
17            int nk = q.size();
18            time++;
19            while(nk--){
20                
21                int row = q.front().first;
22                int col = q.front().second;
23                q.pop();
24
25                for(int i=0;i<4;i++){
26                    int newRow = row + dir[i].first;
27                    int newCol = col + dir[i].second;
28
29                    if(newRow >= 0 && newRow<m && newCol>=0 && newCol < n && grid[newRow][newCol] == 1){
30                        q.push({newRow,newCol});
31                        grid[newRow][newCol] = 2;
32                    }
33                }
34            }
35        }
36        return time;
37        
38    }
39public:
40    int orangesRotting(vector<vector<int>>& grid) {
41        int m = grid.size();
42        int n = grid[0].size();
43
44        vector<vector<int>> vis(m,vector<int>(n,0));
45
46        int minTime = fun(grid,vis);
47
48        for(int i=0;i<m;i++){
49            for(int j=0;j<n;j++){
50                if(grid[i][j] == 1) return -1;
51            }
52        }
53
54        return minTime == -1 ? 0 : minTime;
55        
56    }
57};