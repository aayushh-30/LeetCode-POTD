// Last updated: 3/17/2026, 12:43:00 PM
1class Solution {
2public:
3    bool canMakeArithmeticProgression(vector<int>& arr) {
4        sort(arr.begin(),arr.end());
5        int n = arr.size();
6        int diff = arr[1] - arr[0];
7        for(int i=2;i<n;i++){
8            if(arr[i]-arr[i-1] != diff) return false;
9        }
10
11        return true;
12        
13    }
14};