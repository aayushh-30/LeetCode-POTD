// Last updated: 4/27/2025, 9:25:26 AM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;
        for(int i=2;i<nums.size();i++){
            if((nums[i-1]) == (nums[i-2]+nums[i])*2) count++;
        }
        return count;
        
    }
};