// Last updated: 10/17/2025, 2:06:27 AM
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> mp(value);
        for (auto& x : nums) {
            int v = (x % value + value) % value;
            mp[v]++;
        }
        int mex = 0;
        while (mp[mex % value] > 0) {
            mp[mex % value]--;
            mex++;
        }
        return mex;
    }
};