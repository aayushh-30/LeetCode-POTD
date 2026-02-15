// Last updated: 2/15/2026, 12:49:44 PM
1class Solution {
2public:
3    vector<int> toggleLightBulbs(vector<int>& bulbs) {
4        vector<int> arr(101,0);
5        for(int i=0;i<bulbs.size();i++){
6            arr[bulbs[i]] = (arr[bulbs[i]] + 1) % 2;
7        }
8
9        vector<int> ans;
10        for(int i=0;i<101;i++){
11            if(arr[i] == 1){
12                ans.push_back(i);
13            }
14        }
15        return ans;
16
17        
18    }
19};