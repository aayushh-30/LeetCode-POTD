// Last updated: 1/12/2026, 1:33:54 AM
1class Solution {
2public:
3    int maximalRectangle(vector<vector<char>>& matrix) {
4        if (matrix.empty() || matrix[0].empty()) return 0;
5
6        int M = matrix.size();
7        int N = matrix[0].size();
8
9        
10        vector<vector<int>> mat(M, vector<int>(N));
11        for (int i = 0; i < M; i++) {
12            for (int j = 0; j < N; j++) {
13                mat[i][j] = matrix[i][j] - '0';
14            }
15        }
16
17        
18        for (int i = 0; i < M; i++) {
19            for (int j = 1; j < N; j++) {
20                if (mat[i][j] == 1) {
21                    mat[i][j] += mat[i][j - 1];
22                }
23            }
24        }
25
26        int Ans = 0;
27
28       
29        for (int j = 0; j < N; j++) {
30            for (int i = 0; i < M; i++) {
31                int width = mat[i][j];
32                if (width == 0) continue;
33
34               
35                int currWidth = width;
36                for (int k = i; k < M && mat[k][j] > 0; k++) {
37                    currWidth = min(currWidth, mat[k][j]);
38                    int height = k - i + 1;
39                    Ans = max(Ans, currWidth * height);
40                }
41
42               
43                currWidth = width;
44                for (int k = i; k >= 0 && mat[k][j] > 0; k--) {
45                    currWidth = min(currWidth, mat[k][j]);
46                    int height = i - k + 1;
47                    Ans = max(Ans, currWidth * height);
48                }
49            }
50        }
51
52        return Ans;
53    }
54};