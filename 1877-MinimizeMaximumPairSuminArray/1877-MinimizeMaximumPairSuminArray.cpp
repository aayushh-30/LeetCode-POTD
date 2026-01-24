// Last updated: 1/24/2026, 9:11:16 AM
1class Solution {
2public:
3    int minPairSum(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin(),nums.end());
6        int ans = INT_MIN;
7        for(int i=0;2*i<n;i++){
8            ans = max(ans,nums[i]+nums[n-1-i]);
9        }
10
11        return ans;
12        
13    }
14};