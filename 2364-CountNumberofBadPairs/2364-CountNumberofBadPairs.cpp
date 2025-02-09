class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(nums[i]-i);
        }

        unordered_map<int,int> mp; //number --> frequency;
        long long ans = 0;
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])==mp.end()){
                ans += i;
            }else{
                ans += (i-mp[arr[i]]);
            }
            mp[arr[i]]++;

        }

        return ans;
        
    }
};