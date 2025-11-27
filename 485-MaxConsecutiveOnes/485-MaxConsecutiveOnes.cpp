// Last updated: 11/27/2025, 7:55:41 PM
1class Solution {
2public:
3    int findMaxConsecutiveOnes(vector<int>& nums) {
4        int len = 0;
5        for(int i=0;i<nums.size();i++){
6            int j = i;
7            while(j<nums.size() && nums[j] == 1){
8                j++;
9                len = max(len,j-i);
10            }
11            i = j;
12            
13
14        }
15
16        return len;
17
18        
19    }
20};