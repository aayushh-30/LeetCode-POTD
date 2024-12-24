class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for(auto it:nums){
            totalSum+=it;
        }
        int target = totalSum-x;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int csum = 0;
        int s = -1;
        while(j<n){
            csum+=nums[j];
            while(i<=j && csum>target){
                csum-=nums[i];
                i++;
            }
            if(csum == target){
                s = max(s,j-i+1);
            }
            j++;
        }
        if(s == -1) return -1;
        return n - s;
        
    }
};