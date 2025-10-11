// Last updated: 10/11/2025, 12:03:25 PM
class Solution {
    #define ll long long
    unordered_map<int, int> mp;
    vector<ll> dp;

    ll f(int i, vector<int> &power) {
        if (i >= power.size()) return 0;

        if(dp[i]!=-1) return dp[i];
        
        ll noPick = f(i + 1, power);

        
        ll pick = 0;
        int j = i;
        while (j < power.size() && power[j] - power[i] <= 2) {
            j++;
        }
        pick = (ll)power[i] * mp[power[i]] + f(j, power);

        return dp[i] = max(pick, noPick);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        for (auto it : power) {
            mp[it]++;
        }
        dp.resize(1e6,-1);
        auto last = unique(power.begin(), power.end());
        power.erase(last, power.end());
        return f(0, power);
    }
};