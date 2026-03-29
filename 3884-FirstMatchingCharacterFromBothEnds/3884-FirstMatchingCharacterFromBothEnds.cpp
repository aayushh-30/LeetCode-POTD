// Last updated: 3/29/2026, 10:59:25 AM
1class Solution {
2public:
3    int firstMatchingIndex(string s) {
4        int n = s.length();
5        for(int i=0;i<=n/2;i++){
6            if(s[i] == s[n-1-i]) return i;
7        }
8
9        return -1;
10        
11    }
12};