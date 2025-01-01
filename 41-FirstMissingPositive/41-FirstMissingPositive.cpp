class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int firstMin = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                firstMin = i;
                break;
            }
        }
        if(firstMin == -1 || nums[firstMin] != 1) return 1;
        for(int i = firstMin+1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>1){
                return nums[i-1]+1;
            }
        }
        return nums[n-1]+1;

        
    }
};