// Last updated: 6/22/2025, 12:30:04 PM
class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto [num,fre] : mp){
            if(find(primes.begin(),primes.end(),fre)!=primes.end()) return true;
        }
        return false;
        
    }
};