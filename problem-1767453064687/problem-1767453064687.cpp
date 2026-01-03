// Last updated: 1/3/2026, 8:41:04 PM
1class Solution {
2public:
3    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
4        const long long inf = 2e9;
5        vector<int> a(n,inf);
6
7        a[0] = 0;
8
9        for(auto &r:restrictions){
10            int idx = r[0];
11            int maxVal = r[1];
12            a[idx] = min(a[idx],maxVal);
13        }
14
15        for(int i=0;i<n-1;i++){
16            int lim = a[i]+diff[i];
17            if(lim<a[i+1]){
18                a[i+1] = lim;
19            }
20        }
21
22        for(int i=n-2;i>=0;i--){
23            int limit =a[i+1] + diff[i];
24            if (limit < a[i]) {
25                a[i] = limit;
26            }
27        }
28
29        int ans = 0;
30        for (int i = 0; i < n; i++) {
31            ans = max(ans, a[i]);
32        }
33
34        return ans;
35    }
36};