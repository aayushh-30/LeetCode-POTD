// Last updated: 2/26/2026, 12:41:34 PM
1class Solution {
2public:
3    void divideByTwo(string& s) { s.pop_back(); }
4
5    void addOne(string& s) {
6        int i = s.size() - 1;
7
8        while (i >= 0 && s[i] != '0') {
9            s[i] = '0';
10            i--;
11        }
12
13        if (i < 0) {
14            s = '1' + s;
15        } else {
16            s[i] = '1';
17        }
18    }
19
20    int numSteps(string s) {
21        int N = s.size();
22
23        int operations = 0;
24        while (s.size() > 1) {
25            N = s.size();
26
27            if (s[N - 1] == '0') {
28                divideByTwo(s);
29            } else {
30                addOne(s);
31            }
32
33            operations++;
34        }
35
36        return operations;
37    }
38};