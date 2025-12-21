// Last updated: 12/21/2025, 1:37:15 PM
1class Solution {
2    int reverse(int n){
3        int rev = 0;
4        while(n > 0){
5            int rem = n % 10;
6            rev = rev*10 + rem;
7            n /= 10;
8        }
9        return rev;
10    }
11public:
12    int mirrorDistance(int n) {
13        return abs(n-reverse(n));
14        
15    }
16};