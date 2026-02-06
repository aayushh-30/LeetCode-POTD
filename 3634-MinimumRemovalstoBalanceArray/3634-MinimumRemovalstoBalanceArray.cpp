// Last updated: 2/6/2026, 2:02:18 PM
1class Solution {
2    int fun(vector<int> &nums,int i,int k){
3        int n = nums.size();
4        int mini = nums[i];
5        long long target = 1LL * nums[i] * k;
6        int s = i;
7        int e = n-1;
8        int ans = -1;
9        while(s<=e){
10            int mid = s+(e-s)/2;
11            if(nums[mid]<=target){
12                s = mid + 1;
13                ans = mid;
14            }else{
15                e = mid - 1;
16            }
17        }
18        return ans;
19    }
20public:
21    int minRemoval(vector<int>& nums, int k) {
22        sort(nums.begin(),nums.end());
23        int n = nums.size();
24        vector<int> maxi(n,0);
25        int maxLen = -1;
26        for(int i=0;i<n;i++){
27            int lastidx = fun(nums,i,k);
28            maxi[i] = lastidx-i+1;
29            maxLen = max(maxLen,maxi[i]);
30        }
31
32        return n - maxLen;  
33        
34    }
35};