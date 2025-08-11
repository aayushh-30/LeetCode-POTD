// Last updated: 8/11/2025, 12:30:05 PM
class Solution {
    const int MOD = 1e9 + 7;

    vector<int> fun(int n) {
        vector<int> ans;
        int power = 0;
        while (n > 0) {
            if (n & 1) ans.push_back(1 << power);
            power++;
            n >>= 1;
        }
        sort(ans.begin(), ans.end()); // keep ascending
        return ans;
    }

    vector<long long> preProduct(vector<int>& arr) {
        int n = arr.size();
        vector<long long> preP(n);
        preP[0] = arr[0] % MOD;
        for (int i = 1; i < n; i++) {
            preP[i] = (preP[i - 1] * arr[i]) % MOD;
        }
        return preP;
    }

    long long queryProcessing(int l, int r, vector<long long>& preP) {
        if (l == 0) return preP[r] % MOD;
        long long inv = modInverse(preP[l - 1], MOD);
        return (preP[r] * inv) % MOD;
    }

    long long modPow(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, long long mod) {
        return modPow(a, mod - 2, mod); // Fermat's Little Theorem
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers = fun(n);
        vector<long long> preP = preProduct(powers);

        vector<int> res;
        for (auto& q : queries) {
            res.push_back(queryProcessing(q[0], q[1], preP));
        }
        return res;
    }
};
