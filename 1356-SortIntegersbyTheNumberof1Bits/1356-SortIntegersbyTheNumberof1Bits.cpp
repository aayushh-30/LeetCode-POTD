// Last updated: 2/25/2026, 10:29:36 AM
1class Solution {
2public:
3    vector<int> sortByBits(vector<int>& arr) {
4        sort(arr.begin(),arr.end());
5        map<int,vector<int>> mp;
6        for(int i=0;i<arr.size();i++){
7            int setBits = __builtin_popcount(arr[i]);
8            mp[setBits].push_back(arr[i]);
9        }
10        vector<int> ans,key;
11        for(auto it:mp){
12            key.push_back(it.first);
13        }
14
15        sort(key.begin(),key.end());
16        for(auto it:key){
17            for(auto k:mp[it]){
18                ans.push_back(k);
19            }
20        }
21
22        return ans;
23        
24        
25    }
26};