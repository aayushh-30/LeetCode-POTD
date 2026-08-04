// Last updated: 8/4/2026, 11:31:35 AM
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        int n = nums.size();
5        ranges::sort(nums);
6        vector<int> ans;
7        for (int i = 0; i < n - 1; i++) {
8            for (int j = nums[i] + 1; j < nums[i + 1]; j++) {
9                ans.push_back(j);
10            }
11        }
12        return ans;
13    }
14};