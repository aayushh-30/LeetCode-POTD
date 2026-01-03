// Last updated: 1/3/2026, 8:27:27 PM
1class Solution {
2public:
3    int minLength(vector<int>& nums, int k) {
4        vector<int> cp = nums;
5        unordered_map<int,int> mp;
6
7        long long ds = 0;
8        int l = 0;
9        int ans = INT_MAX;
10
11        for(int i=0;i<nums.size();i++){
12            if(mp[nums[i]] == 0){
13                ds += nums[i];
14            }
15            mp[nums[i]]++;
16
17            while(ds >= k){
18                ans = min(ans,i-l+1);
19                mp[nums[l]]--;
20                if(mp[nums[l]] == 0){
21                    ds -= nums[l];
22                }
23                l++;
24                
25            }
26        }
27
28        return ans == INT_MAX ? -1 : ans;
29        
30    }
31};