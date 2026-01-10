// Last updated: 1/10/2026, 12:48:29 PM
1class Solution {
2    vector<int> ar1,ar2;
3    vector<vector<int>> dp;
4    int fun(int i,int j,string &s1,string &s2){
5        if(i == s1.length() && j == s2.length()) return 0;
6        if(i == s1.length()){
7            return ar2[j];
8        }
9        if(j == s2.length()){
10            return ar1[i];
11        }
12
13        if(dp[i][j]!=-1) return dp[i][j];
14
15        int ans = INT_MAX;
16        if(s1[i] == s2[j]){
17            ans = min(ans,fun(i+1,j+1,s1,s2));
18        }
19
20        return dp[i][j] = ans = min({ans,fun(i+1,j,s1,s2)+s1[i],fun(i,j+1,s1,s2)+s2[j]});
21    }
22    
23public:
24    int minimumDeleteSum(string s1, string s2) {
25        int m = s1.length();
26        int n = s2.length();
27        ar1.resize(m,0);
28        ar2.resize(n,0);
29        dp.resize(m+1,vector<int>(n+1,-1));
30        ar1[m-1] = s1[m-1];
31        for(int i=m-2;i>=0;i--){
32            ar1[i] = ar1[i+1]+s1[i];
33        }
34        ar2[n-1] = s2[n-1];
35        for(int i=n-2;i>=0;i--){
36            ar2[i] = ar2[i+1]+s2[i];
37        }
38
39        return fun(0,0,s1,s2);
40        
41        
42    }
43};