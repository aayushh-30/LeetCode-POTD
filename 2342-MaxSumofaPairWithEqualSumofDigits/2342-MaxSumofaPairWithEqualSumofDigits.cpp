class Solution {
    int sumOfDigits(int n){
        int sum = 0;
        while(n>0){
            sum += (n%10);
            n/=10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = -1;
        for(int i=0;i<nums.size();i++){
            int key = sumOfDigits(nums[i]);
            if(mp.find(key)!=mp.end()){
                ans = max(ans,nums[i] + mp[key]);
                mp[key] = max(nums[i],mp[key]);
            }else{
                mp[key] = nums[i];
            }
        }

        return ans;

        
    }
};