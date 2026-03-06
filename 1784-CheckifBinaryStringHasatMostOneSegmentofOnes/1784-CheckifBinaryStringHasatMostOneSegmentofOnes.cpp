// Last updated: 3/6/2026, 9:35:41 AM
1class Solution {
2public:
3    bool checkOnesSegment(string s) {
4        int i = 0;
5        int n = s.length();
6        int cnt = 0;
7        while (i < n) {
8            if (s[i] == '1') {
9                int j = i;
10                while (j < n && s[i] == s[j] && s[j] == '1') {
11                    j++;
12                }
13                if (j - i  > 0) cnt++;
14                   
15                i = j;
16            } else {
17                i++;
18            }
19        }
20
21        return cnt == 1;
22    }
23};