class Solution {
    bool isValid(vector<int>& nums,int mid, int k){
        int sum = 0;
        int count = 1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum += nums[i];
            }else{
                count++;
                sum = nums[i];
            }
        }

        return count <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);

        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(nums,mid,k)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        return ans;
        
    }
};