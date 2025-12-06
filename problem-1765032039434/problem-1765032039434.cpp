// Last updated: 12/6/2025, 8:10:39 PM
1class Solution {
2    bool fun(long long n) {
3        if (n < 2) return false;
4        if (n % 2 == 0) return n == 2;
5        for (long long i = 3; i * i <= n; i += 2)
6            if (n % i == 0) return false;
7        return true;
8    }
9public:
10    bool completePrime(int num) {
11        string s = to_string(num);
12        int n = s.size();
13
14
15        for (int i = 1; i <= n; i++) {
16            int prefix = stoi(s.substr(0, i));
17            if (!fun(prefix)) return false;
18        }
19
20        for (int i = 0; i < n; i++) {
21            int suffix = stoi(s.substr(i));
22            if (!fun(suffix)) return false;
23        }
24
25        return true;
26        
27    }
28};