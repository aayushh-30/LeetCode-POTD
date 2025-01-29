class Solution {
    vector<vector<int>> dp;
    
    int fun1(int k, int start) {
        if (k == 0) return 1;
        if (dp[k][start] != -1) return dp[k][start];
        
        int count = 0;
        for (int j = start; j < 5; j++) {
            count += fun1(k - 1, j);
        }
        return dp[k][start] = count;
    }

public:
    int countVowelStrings(int n) {
        dp.resize(n + 1, vector<int>(5, -1));
        return fun1(n, 0);
    }
};
