// Last updated: 4/19/2026, 8:16:12 PM
1class Solution {
2public:
3    int firstStableIndex(vector<int>& nums, int k) {
4        int n = nums.size();
5        vector<int> prevMax(n,-1e9),postMin(n,1e9);
6        prevMax[0] = nums[0];
7        for(int i=1;i<n;i++){
8            prevMax[i] = max(prevMax[i-1],nums[i]);
9        }
10
11        postMin[n-1] = nums[n-1];
12        for(int i=n-2;i>=0;i--){
13            postMin[i] = min(postMin[i+1],nums[i]);
14        }
15
16        for(int i=0;i<n;i++){
17            if(prevMax[i] - postMin[i]<=k){
18                return i;
19            }
20        }
21
22        return -1;
23        
24    }
25};