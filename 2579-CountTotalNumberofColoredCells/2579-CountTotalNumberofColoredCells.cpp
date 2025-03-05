class Solution {
public:
    long long coloredCells(int n) {
        n--;
        long long ans = (long long)4*((long long)n*(1ll*n+1)/2);
        return ans + 1;
        
    }
};