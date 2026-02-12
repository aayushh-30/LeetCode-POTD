// Last updated: 2/12/2026, 9:36:50 PM
1class Solution {
2public:
3    int maximumPopulation(vector<vector<int>>& logs) {
4        vector<vector<int>> lg;
5        for(int i=0;i<logs.size();i++){
6            lg.push_back({logs[i][0],1});
7            lg.push_back({logs[i][1],-1});
8        }
9        int maxi = 0;
10        int curr = 0;
11        int maxiYear = logs[0][0];
12        sort(lg.begin(),lg.end());
13        for(int i=0;i<lg.size();i++){
14            curr += lg[i][1];
15            if(curr > maxi){
16                maxi = curr;
17                
18                maxiYear = lg[i][0];
19            }
20        }
21
22        return maxiYear;
23        
24    }
25};