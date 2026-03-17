// Last updated: 3/17/2026, 12:54:32 PM
1class Solution {
2public:
3    bool isPalindrome(int x) {
4        if(x<0) return false;
5        int temp = x;
6        long long n = 0;
7        while(temp){
8            n = (n * 10) + (temp % 10);
9            temp /= 10;
10        }
11
12        return x == n;
13        
14    }
15};