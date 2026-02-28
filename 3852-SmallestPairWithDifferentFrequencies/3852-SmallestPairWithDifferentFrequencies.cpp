// Last updated: 2/28/2026, 11:33:17 PM
1class Solution {
2public:
3    vector<int> minDistinctFreqPair(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        unordered_map<int,int> mp;
6        for(int i=0;i<nums.size();i++){
7            mp[nums[i]]++;
8        }
9        int prevFreq = mp[nums[0]];
10        for(int i=0;i<nums.size();i++){
11            if(nums[i] != nums[0] && mp[nums[i]]!=prevFreq){
12                return {nums[0],nums[i]};
13            }
14        }
15
16        return {-1,-1};
17        
18    }
19};