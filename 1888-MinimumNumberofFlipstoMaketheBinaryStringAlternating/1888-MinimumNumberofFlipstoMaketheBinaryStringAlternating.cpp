// Last updated: 3/7/2026, 8:59:35 AM
1class Solution {
2public:
3    int minFlips(string s) {
4        int n = s.size();
5        string t = s + s;
6
7        int ans = n;
8        int mis0 = 0;
9
10        for(int i = 0; i < 2*n; i++) {
11
12            char expected = (i % 2 == 0) ? '0' : '1';
13
14            if(t[i] != expected) mis0++;
15
16            if(i >= n) {
17                int left = i - n;
18                char exp_left = (left % 2 == 0) ? '0' : '1';
19                if(t[left] != exp_left) mis0--;
20            }
21
22            if(i >= n - 1) {
23                int mis1 = n - mis0;
24                ans = min(ans, min(mis0, mis1));
25            }
26        }
27
28        return ans;
29    }
30};