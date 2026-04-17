// Last updated: 4/17/2026, 8:15:33 PM
1class Solution {
2    int reverseNum(int num){
3        int rev = 0;
4        while(num > 0){
5            rev = rev * 10 + (num % 10);
6            num /= 10;
7        }
8        return rev;
9    }
10public:
11    int minMirrorPairDistance(vector<int>& nums) {
12        unordered_map<int,int> mp;  
13        int ans = INT_MAX;
14
15        for(int i = 0; i < nums.size(); i++){
16
17            if(mp.find(nums[i]) != mp.end()){
18                ans = min(ans, i - mp[nums[i]]);
19            }
20            
21            int r = reverseNum(nums[i]);
22
23            
24                mp[r] = i;
25        }
26
27        return ans == INT_MAX ? -1 : ans;
28    }
29};
30