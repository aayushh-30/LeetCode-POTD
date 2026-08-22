// Last updated: 8/22/2026, 10:40:14 AM
1public class Solution {
2    public bool CheckDivisibility(int n) {
3        int ds = 0;
4        int dp = 1;
5        int cp = n;
6        while(n>0){
7            int d = n % 10;
8            ds += d;
9            dp *= d;
10            n /= 10;
11        }
12        return cp % (dp+ds) == 0 ;
13        
14    }
15}