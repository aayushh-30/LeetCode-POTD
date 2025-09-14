// Last updated: 9/14/2025, 9:53:02 AM
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n = nums.size() - 1;
        ans.push_back(nums[n]);
        n--;
        k--;
        while(k>0 && n >= 0){
            int last = ans.back();
            if(last != nums[n]){
                ans.push_back(nums[n]);
                k--;
            }
            n--;
        }

        return ans;
        
    }
};