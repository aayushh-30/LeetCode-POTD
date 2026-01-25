// Last updated: 1/25/2026, 11:56:25 AM
1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int n = nums.size();
6        int ans = INT_MAX;
7        for(int i=0;i<=n-k;i++){
8            ans = min(ans,abs(nums[i]-nums[i+k-1]));
9        }
10        return ans;
11        
12    }
13};