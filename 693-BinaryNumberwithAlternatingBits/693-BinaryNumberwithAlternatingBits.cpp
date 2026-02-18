// Last updated: 2/18/2026, 11:53:50 AM
1class Solution {
2public:
3    bool hasAlternatingBits(int n) {
4        int res = -1;
5        while(n > 0){
6            if(res == (n & 1)){
7                return false;
8            }
9            res = (n & 1);
10            n = n >> 1;
11            
12        }
13        return true;
14        
15    }
16};