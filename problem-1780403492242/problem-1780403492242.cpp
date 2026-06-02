// Last updated: 6/2/2026, 6:01:32 PM
1class Solution {
2public:
3    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
4                           vector<int>& waterStartTime, vector<int>& waterDuration) {
5        int minFinishTime = INT_MAX;
6
7        int n = landStartTime.size();
8        int m = waterStartTime.size();
9
10        for (int i = 0; i < n; ++i) {       
11            for (int j = 0; j < m; ++j) {    
12                int landStart = landStartTime[i];
13                int landDur = landDuration[i];
14                int waterStart = waterStartTime[j];
15                int waterDur = waterDuration[j];
16
17                int landBegin = landStart;
18                int landEnd = landBegin + landDur;
19
20                int waterBeginAfterLand = max(landEnd, waterStart);
21                int finishTime1 = waterBeginAfterLand + waterDur;
22
23                
24                int waterBegin = waterStart;
25                int waterEnd = waterBegin + waterDur;
26
27                int landBeginAfterWater = max(waterEnd, landStart);
28                int finishTime2 = landBeginAfterWater + landDur;
29
30                
31                minFinishTime = min({minFinishTime, finishTime1, finishTime2});
32            }
33        }
34
35        return minFinishTime;
36    }
37};
38