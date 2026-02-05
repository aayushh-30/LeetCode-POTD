// Last updated: 2/5/2026, 12:27:19 PM
1class Solution {
2public:
3    vector<int> constructTransformedArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> ans(n,0);
6        for(int i=0;i<n;i++){
7            if(nums[i]>0){
8                int idx = (i + nums[i])%n;
9                ans[i] = nums[idx];
10
11            }else if(nums[i]<0){
12                int idx = (i + nums[i])%n;
13                if(idx<0) idx += n;
14                ans[i] = nums[idx];
15
16            }else{
17                ans[i] = nums[i];
18            }
19        }
20        return ans;
21        
22    }
23};