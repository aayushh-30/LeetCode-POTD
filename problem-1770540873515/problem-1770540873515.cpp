// Last updated: 2/8/2026, 2:24:33 PM
1class Solution {
2public:
3    int dominantIndices(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> postSum(n,0);
6        postSum[n-1] = nums[n-1];
7        for(int i=n-2;i>=0;i--){
8            postSum[i] = nums[i] + postSum[i+1];
9        }
10        for(int i=0;i<n;i++){
11            cout<<postSum[i]<<" ";
12        }
13
14        int ans = 0;
15        for(int i=0;i<n-1;i++){
16            int currNum = nums[i];
17            int aheadSum = postSum[i] - nums[i];
18            float avg = (((float)aheadSum)/(n-i-1));
19            if(currNum>avg) ans++;
20
21        }
22
23        return ans;
24        
25    }
26};