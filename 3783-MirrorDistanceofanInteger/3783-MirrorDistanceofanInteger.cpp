// Last updated: 12/21/2025, 2:09:10 PM
1#define ll long long
2class Solution {
3public:
4    long long minCost(string s, vector<int>& cost) {
5        unordered_map<char,ll> mp;
6        for(int i=0;i<s.length();i++){
7            mp[s[i]] += cost[i];
8        }
9        if(mp.size() == 1) return 0;
10        ll total = accumulate(cost.begin(),cost.end(),0LL);
11
12        ll ans = total;
13        for(auto it:mp){
14            ll cost = it.second;
15            ans = min(ans,total-cost);
16
17        }
18        return ans;
19        
20        
21    }
22};