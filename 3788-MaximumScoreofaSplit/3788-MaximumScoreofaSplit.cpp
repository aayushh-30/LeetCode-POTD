// Last updated: 12/28/2025, 7:09:21 PM
1class Solution {
2public:
3    long long maximumScore(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> mini(n);
6        mini[n-1] = nums[n-1];
7        for(int j=n-2;j>=0;j--){
8            mini[j] = min(nums[j],mini[j+1]);
9        }
10
11        long long sum = 0;
12        long long ans = LLONG_MIN;
13        for(int i=0;i<n-1;i++){
14            sum += nums[i];
15            ans = max(ans,sum - mini[i+1]);
16
17        }
18        return ans;  
19    }
20};