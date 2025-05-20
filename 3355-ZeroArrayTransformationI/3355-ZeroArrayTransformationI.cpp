// Last updated: 5/20/2025, 9:28:47 PM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n, 0);

        // Update the difference array based on queries
        for (const auto& q : queries) {
            int s = q[0];
            int e = q[1];
            diff[s] -= 1;
            if (e + 1 < n) diff[e + 1] += 1;
        }

        int currentEffect = 0;  // To accumulate the effect while traversing
        for (int i = 0; i < n; i++) {
            currentEffect += diff[i];
            if (nums[i] + currentEffect > 0) return false;
        }

        return true;
    }
};
