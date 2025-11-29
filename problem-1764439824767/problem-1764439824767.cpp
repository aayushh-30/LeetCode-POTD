// Last updated: 11/29/2025, 11:40:24 PM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int k) {
4
5        int sum = accumulate(nums.begin(),nums.end(),0);
6        return sum % k;
7        
8    }
9};