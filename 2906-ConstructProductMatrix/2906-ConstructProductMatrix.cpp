// Last updated: 3/24/2026, 10:56:42 AM
1class Solution {
2public:
3    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6
7        vector<vector<int>> pre(m,vector<int>(n,1));
8        vector<vector<int>> post(m,vector<int>(n,1));
9        int preProduct = 1;
10        int postProduct = 1;
11        for(int i=0;i<m;i++){
12            for(int j=0;j<n;j++){
13                pre[i][j] = preProduct;
14                
15                preProduct *= (grid[i][j] %= 12345);
16                preProduct %= 12345;
17                post[m-1-i][n-1-j] = postProduct;
18                postProduct *= (grid[m-1-i][n-1-j]%= 12345);
19                postProduct %= 12345;
20            }
21        }
22
23        for(int i=0;i<m;i++){
24            for(int j=0;j<n;j++){
25                pre[i][j] *= post[i][j];
26                pre[i][j] %= 12345;
27            }
28        }
29
30        return pre;
31        
32        
33    }
34};