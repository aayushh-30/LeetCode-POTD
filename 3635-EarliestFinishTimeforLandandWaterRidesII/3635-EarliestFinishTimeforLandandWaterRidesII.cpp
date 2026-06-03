// Last updated: 6/3/2026, 11:38:28 PM
1class Solution {
2    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2,
3              vector<int>& duration2) {
4        int finish1 = INT_MAX;
5        for (int i = 0; i < start1.size(); i++) {
6            finish1 = min(finish1, start1[i] + duration1[i]);
7        }
8
9        int finish2 = INT_MAX;
10        for (int i = 0; i < start2.size(); i++) {
11            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
12        }
13        return finish2;
14    }
15
16public:
17    int earliestFinishTime(vector<int>& landStartTime,
18                           vector<int>& landDuration,
19                           vector<int>& waterStartTime,
20                           vector<int>& waterDuration) {
21        int land_water =
22            solve(landStartTime, landDuration, waterStartTime, waterDuration);
23        int water_land =
24            solve(waterStartTime, waterDuration, landStartTime, landDuration);
25        return min(land_water, water_land);
26    }
27};