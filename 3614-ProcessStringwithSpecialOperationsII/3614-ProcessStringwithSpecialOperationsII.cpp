// Last updated: 6/17/2026, 11:40:02 AM
1class Solution {
2public:
3    char processStr(string s, long long k) {
4        long long len = 0;
5        for (auto c : s) {
6            if (c == '*') {
7                if (len) {
8                    len--;
9                }
10            } else if (c == '#') {
11                len *= 2;
12            } else if (c == '%') {
13                continue;
14            } else {
15                len++;
16            }
17        }
18        if (k + 1 > len) {
19            return '.';
20        }
21        for (int i = s.size() - 1; i >= 0; i--) {
22            if (s[i] == '*') {
23                len++;
24            } else if (s[i] == '#') {
25                if (k + 1 > (len + 1) / 2) {
26                    k -= len / 2;
27                }
28                len = (len + 1) / 2;
29            } else if (s[i] == '%') {
30                k = len - k - 1;
31            } else {
32                if (k + 1 == len) {
33                    return s[i];
34                } else {
35                    len--;
36                }
37            }
38        }
39        return '.';
40    }
41};