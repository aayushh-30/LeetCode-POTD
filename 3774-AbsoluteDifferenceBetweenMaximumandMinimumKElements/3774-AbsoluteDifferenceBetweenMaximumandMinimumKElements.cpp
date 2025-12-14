// Last updated: 12/14/2025, 11:40:58 AM
1class Solution {
2public:
3    int absDifference(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int n = nums.size();
6        int minSum = 0;
7        int maxSum = 0;
8        for(int i=0;i<k;i++){
9            minSum += nums[i];
10            maxSum += nums[n-1-i];
11        }
12
13        return abs(minSum-maxSum);
14        
15    }
16};