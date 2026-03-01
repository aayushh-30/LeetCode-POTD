// Last updated: 3/2/2026, 12:55:19 AM
1class Solution {
2public:
3    int minPartitions(string n) {
4        int ans = 0;
5        for (char& c : n) ans = max(ans, c - '0');
6        return ans;
7    }
8};