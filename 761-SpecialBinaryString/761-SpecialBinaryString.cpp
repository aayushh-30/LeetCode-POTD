// Last updated: 2/20/2026, 10:32:53 AM
1class Solution {
2public:
3    string makeLargestSpecial(string s) {
4        int i = 0;
5        int one = 0;
6        int zero = 0;
7        int n = s.size();
8        vector<string> res;
9        for (int j = 0; j < n; j++) {
10            if (s[j] == '1') {
11                one++;
12            } else {
13                zero++;
14            }
15            if (one == zero) {
16                res.push_back(
17                    '1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
18                i = j + 1;
19            }
20        }
21        sort(res.rbegin(), res.rend());
22        string ans;
23        for (auto str : res) {
24            ans += str;
25        }
26        return ans;
27    }
28};