// Last updated: 1/1/2026, 11:05:49 AM
1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        if (digits.size() == 0) return digits;
5        if (digits[digits.size() - 1] != 9) {
6            digits[digits.size() - 1]++;
7        } else {
8            int k = digits.size() - 1;
9            while (k > 0 && digits[k] == 9) {
10                digits[k] = 0;
11                k--;
12            }
13            digits[k]++;
14            if (digits[0] == 10) {
15                digits[0] = 0;
16                digits.insert(digits.begin(), 1);
17            }
18        }
19        return digits;
20        
21    }
22};