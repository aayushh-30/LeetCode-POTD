class Solution {
    #define MOD 1000000007
    int fun(int n){
        int rev = 0;
        while(n){
            int k = n % 10;
            rev = rev * 10 + k;
            n = n / 10;
        }
        //cout<<rev<<" ";
        return rev;
    }
public:
    int countNicePairs(vector<int>& nums) {
        vector<int> reversed;
        for(auto it:nums){
            int rev = fun(it);
            //cout<<rev<<" ";
            reversed.push_back(rev);
        }
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int it = nums[i] - reversed[i];
            if(mp.find(it) != mp.end()){
                ans =( ans + (mp[it])%MOD)%MOD;
            }
            mp[it]++;
        }

        return ans;
        
    }
};