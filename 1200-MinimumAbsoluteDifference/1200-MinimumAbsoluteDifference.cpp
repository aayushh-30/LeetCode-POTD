// Last updated: 1/26/2026, 11:27:46 AM
1class Solution {
2public:
3    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
4        sort(arr.begin(),arr.end());
5        int mini = INT_MAX;
6        for(int i=0;i<arr.size()-1;i++){
7            mini = min(mini,arr[i+1]-arr[i]);
8        }
9
10        vector<vector<int>> res;
11        
12        for(int i=0;i<arr.size()-1;i++){
13            vector<int> ans;
14            if(arr[i+1]-arr[i]==mini){
15                ans.push_back(arr[i]);
16                ans.push_back(arr[i+1]);
17                 res.push_back(ans);
18            }
19           
20        }
21
22        return res;
23
24
25
26        
27    }
28};