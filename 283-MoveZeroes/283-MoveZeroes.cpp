// Last updated: 11/27/2025, 7:31:21 PM
1class Solution {
2public:
3    void moveZeroes(vector<int>& nums) {
4        int idx = 0;
5        int n = nums.size();
6        for(int i=0;i<n;i++){
7            if(nums[i] != 0){
8                nums[idx] = nums[i];
9                idx++;
10            }
11        }
12        for(int k=idx;k<n;k++){
13            nums[k] = 0;
14        }
15        
16    }
17};