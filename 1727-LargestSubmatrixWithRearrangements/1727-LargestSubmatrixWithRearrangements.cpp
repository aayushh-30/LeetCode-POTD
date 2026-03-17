// Last updated: 3/17/2026, 11:39:40 PM
1class Solution {
2public:
3    int largestSubmatrix(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6        int ans = 0;
7        
8        for (int row = 0; row < m; row++) {
9            for (int col = 0; col < n; col++) {
10                if (matrix[row][col] != 0 && row > 0) {
11                    matrix[row][col] += matrix[row - 1][col];
12                }
13            }
14            
15            vector<int> currRow = matrix[row];
16            sort(currRow.begin(), currRow.end(), greater());
17            for (int i = 0; i < n; i++) {
18                ans = max(ans, currRow[i] * (i + 1));
19            }
20        }
21        
22        return ans;
23    }
24};