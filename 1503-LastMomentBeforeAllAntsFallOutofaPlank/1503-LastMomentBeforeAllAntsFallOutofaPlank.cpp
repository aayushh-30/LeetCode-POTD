// Last updated: 12/5/2025, 12:27:32 AM
1class Solution {
2public:
3    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
4        int ans = 0;
5
6        for(int i=0;i<left.size();i++){
7            ans = max(ans,left[i]-0);
8        }
9        for(int i=0;i<right.size();i++){
10            ans = max(ans,n-right[i]);
11        }
12
13        return ans;
14
15        
16    }
17};