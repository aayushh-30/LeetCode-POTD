class Solution {
    #define MOD 1000000007
public:
    int monkeyMove(int n) {
        int a = 2;
        int totalWays = 1;
        while (n > 0) {
            if (n % 2 != 0) {
                totalWays = (1LL * totalWays * a) % MOD;
            }
            a = (1LL * a * a) % MOD;
            n /= 2;
        }
        totalWays = (totalWays - 2 + MOD) % MOD;
        return totalWays;
    }
};
