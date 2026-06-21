// Last updated: 6/21/2026, 8:13:34 AM
1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        sort(costs.begin(),costs.end());
5        int ans = 0;
6        int i = 0;
7        int n = costs.size();
8        while(i < n && coins >= costs[i]){
9            ans++;
10            coins -= costs[i];
11            i++;
12        }
13
14        return ans;
15        
16    }
17};