// Last updated: 11/16/2025, 8:07:34 AM
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return nums[n-1]+nums[n-2]-nums[0];
        
    }
};