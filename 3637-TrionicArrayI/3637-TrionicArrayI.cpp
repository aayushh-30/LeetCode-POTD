// Last updated: 2/4/2026, 12:19:06 AM
1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4        int inc = 0;
5        int dec = 0;
6        int n = nums.size();
7        vector<int> diff(n,0);
8        for(int i=1;i<n;i++){
9            diff[i] = nums[i] - nums[i-1];
10        }
11        
12        int i = 1;
13        while(i<n){
14            if(i<n && diff[i] == 0) return false;
15            if(i<n && diff[i]<0){
16                dec++;
17                while(i<n && diff[i]<0) i++;
18            }
19            if(i<n && diff[i]>0){
20                inc++;
21                while(i<n && diff[i]>0) i++;
22            }
23        }
24
25        return inc == 2 && dec == 1;
26    }
27};