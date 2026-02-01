// Last updated: 2/1/2026, 2:36:54 PM
1class Solution {
2public:
3    int finalElement(vector<int>& nums) {
4        int n = nums.size();
5
6        return max(nums[0],nums[n-1]);
7        
8    }
9};