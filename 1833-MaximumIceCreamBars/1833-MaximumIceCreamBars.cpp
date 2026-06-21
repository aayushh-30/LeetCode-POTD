// Last updated: 6/21/2026, 8:12:48 AM
1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        sort(costs.begin(),costs.end());
5        int ans = 0;
6        for(int i=0;i<costs.size();i++){
7            if(coins >= costs[i]){
8                coins -= costs[i];
9                ans++;
10            }
11        }
12        return ans;
13        
14    }
15};