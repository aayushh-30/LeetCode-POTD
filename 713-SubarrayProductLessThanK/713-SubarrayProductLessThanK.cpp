// Last updated: 3/28/2026, 11:33:40 PM
1class Solution {
2public:
3    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
4        int ans = 0;
5        int i = 0;
6        int j = 0;
7        int n = nums.size();
8        int pd = 1;
9
10
11        while(j<n){
12            pd *= nums[j];
13            while(i<=j && pd >= k){
14                pd /= nums[i];
15                i++;
16            }
17            ans += (j-i+1);
18            j++;
19
20        }
21
22        return ans;
23        
24    }
25};