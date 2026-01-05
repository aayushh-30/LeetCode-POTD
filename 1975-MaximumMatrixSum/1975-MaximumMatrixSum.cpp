// Last updated: 1/5/2026, 6:43:10 PM
1class Solution {
2public:
3    long long maxMatrixSum(vector<vector<int>>& matrix) {
4        long long ans = 0;
5        int negativeCount = 0;
6        int mini = INT_MAX;
7        int n = matrix.size();
8        for(int i=0;i<n;i++){
9            for(int j=0;j<n;j++){
10                if(matrix[i][j]<0) negativeCount++;
11                ans += abs(matrix[i][j]);
12                mini = min(mini,abs(matrix[i][j]));
13            }
14        }
15
16        if(negativeCount%2==0) return ans;
17        return ans - 2*mini;
18        
19    }
20};