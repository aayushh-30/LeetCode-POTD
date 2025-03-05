class Solution {
    int fun(vector<vector<int>> &arr, int startsFrom) {
        int i = 0, j = arr.size() - 1;
        int idx = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (arr[mid][0] >= startsFrom) {
                idx = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return idx;
    }

public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        unordered_map<int, int> mp;
        vector<vector<int>> copy = intervals;
        
        for (int i = 0; i < n; i++) {
            mp[intervals[i][0]] = i;
        }

        sort(copy.begin(), copy.end());
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int idx = fun(copy, intervals[i][1]);
            if (idx != -1) {
                ans[i] = mp[copy[idx][0]];
            }
        }

        return ans;
    }
};