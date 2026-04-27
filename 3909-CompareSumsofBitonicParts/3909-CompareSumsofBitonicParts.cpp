// Last updated: 4/28/2026, 12:33:14 AM
1class Solution {
2public:
3    int compareBitonicSums(vector<int>& nums) {
4        int low=0,high=nums.size()-1,mid;
5        while(low<=high){
6            mid=(low+high)/2;
7            if(mid>0&&mid<nums.size()-1&&nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]) break;
8            else if(nums[mid]<nums[mid+1]) low=mid+1;
9            else high=mid-1;
10        }
11        long long x=0,y=0;
12        for(int i=0;i<=mid;i++) x+=nums[i];
13        for(int j=mid;j<nums.size();j++) y+=nums[j];
14        if(x>y) return 0;
15        else if(y>x) return 1;
16        return -1;
17    }
18};