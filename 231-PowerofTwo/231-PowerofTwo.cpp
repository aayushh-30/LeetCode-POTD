// Last updated: 8/9/2025, 4:40:56 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n & (n-1)) == 0;
        
    }
};