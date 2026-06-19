// Last updated: 6/19/2026, 10:50:50 AM
1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        int ans = gain[0];
5        int maxi = gain[0];
6        for(int i=1;i<gain.size();i++){
7            maxi += gain[i];
8            ans = max(ans,maxi);
9        }
10        return ans < 0 ? 0 : ans;
11        
12    }
13};