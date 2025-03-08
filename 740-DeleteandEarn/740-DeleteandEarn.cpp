class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        unordered_map<int, int> freq;
        int maxNum = 0;

        for(int num : nums) {
            freq[num] += num; 
            maxNum = max(maxNum, num);
        }

        
        int prev1 = 0, prev2 = 0;
        for(int i = 0; i <= maxNum; i++) {
            int take = freq[i] + prev2; 
            int notTake = prev1;         
            
            int curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
