// Last updated: 3/11/2026, 8:29:39 AM
class Solution {
public:
    int bitwiseComplement(int n) {
        int bits = log2(n) + 1;
        int mask = (1 << bits) - 1;
        return mask ^ n;
    }
};