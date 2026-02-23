// Last updated: 2/23/2026, 11:20:12 AM
1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4        unordered_map<string,int> mp;
5        int n = s.length();
6        for(int i=0;i<=n-k;i++){
7            string sub = s.substr(i,k);
8            mp[sub]++;
9        }
10        return mp.size() == pow(2,k);
11    }
12};