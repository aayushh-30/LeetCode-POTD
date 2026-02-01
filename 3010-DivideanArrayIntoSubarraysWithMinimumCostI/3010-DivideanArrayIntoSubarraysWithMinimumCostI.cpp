// Last updated: 2/1/2026, 2:46:27 PM
1class Solution {
2public:
3    int minimumCost(vector<int>& nums) {
4        int cost = nums[0];
5        sort(nums.begin()+1,nums.end());
6        return cost + nums[1]+nums[2];
7
8        
9    }
10};