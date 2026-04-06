// Last updated: 4/6/2026, 8:52:23 PM
1class Solution {
2public:
3    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
4        vector<int> DX = {0, 1, 0, -1};
5        vector<int> DY = {1, 0, -1, 0};
6
7        set<pair<int, int>> st;
8        for (auto &k : obstacles) {
9            st.insert({k[0], k[1]});
10        }
11
12        int x = 0, y = 0, dir = 0, ans = 0;
13
14        for (int i = 0; i < commands.size(); i++) {
15            if (commands[i] == -1) {
16                dir = (dir + 1) % 4;  // Turn right
17            } else if (commands[i] == -2) {
18                dir = (dir + 3) % 4;  // Turn left
19            } else {
20                for (int step = 0; step < commands[i]; step++) {
21                    int newX = x + DX[dir];
22                    int newY = y + DY[dir];
23
24                    if (st.find({newX, newY}) != st.end()) {
25                        break;  // Stop moving in this direction if an obstacle is encountered
26                    }
27
28                    x = newX;
29                    y = newY;
30                    ans = max(ans, x * x + y * y);
31                }
32            }
33        }
34
35        return ans;
36    }
37};
38