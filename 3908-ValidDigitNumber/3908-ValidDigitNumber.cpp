// Last updated: 4/28/2026, 12:17:19 AM
1class Solution {
2    bool cntX(int n, int x, int& ld) {
3        int cnt = 0;
4        while (n > 0) {
5            ld = n % 10;
6            if (ld == x) cnt++;
7            n /= 10;
8        }
9        return cnt >= 1;
10    }
11
12public:
13    bool validDigit(int n, int x) {
14        int ld = 1e9;
15        
16        bool hd = cntX(n,x,ld);
17        return hd && (ld != x);
18    }
19};