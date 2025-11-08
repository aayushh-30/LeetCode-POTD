// Last updated: 11/8/2025, 11:12:44 PM
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n==0) return 0;//base case
        int k=31-__builtin_clz(n);
        int numOp=(1<<(k+1))-1;
        return numOp-minimumOneBitOperations(n^(1<<k));
    }
};