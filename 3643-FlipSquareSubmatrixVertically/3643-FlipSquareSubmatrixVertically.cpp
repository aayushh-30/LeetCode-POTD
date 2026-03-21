// Last updated: 3/21/2026, 11:23:32 AM
1class Solution {
2public:
3    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int i = x;
7        int j = i + k - 1;
8        while(i<=j){
9            for(int a=y;a<y+k;a++){
10                swap(grid[i][a],grid[j][a]);
11            }
12            i++;
13            j--;
14        }
15
16        return grid;
17        
18    }
19};