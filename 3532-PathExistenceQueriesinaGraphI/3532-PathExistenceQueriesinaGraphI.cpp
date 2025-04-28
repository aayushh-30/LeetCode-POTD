// Last updated: 4/28/2025, 11:05:42 PM
class Solution {
    // Binary search to find the furthest reachable index
    int upperBound(int i, int maxDiff, vector<int>& nums) {
        int idx = -1;
        int s = i;
        int e = nums.size() - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (abs(nums[m] - nums[i]) <= maxDiff) {
                s = m + 1;
                idx = m;
            } else {
                e = m - 1;
            }
        }
        return idx;
    }

    // Disjoint Set Union (DSU) or Union-Find
    class DSU {
    public:
        vector<int> parent;

        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px != py) {
                parent[px] = py;
            }
        }
    };

    vector<bool> doPathExist(int n, vector<int>& nums, int maxDiff,
                             vector<vector<int>>& queries) {
        DSU dsu(n);
        vector<int> next(n);
        for (int i = 0; i < n; i++) next[i] = i + 1;

        for (int i = 0; i < n; i++) {
            int ub = upperBound(i, maxDiff, nums);
            if (ub == i)
                continue;

            // Union directly with next node
            
            for (int j = i + 1; j <= ub; j++) {
                dsu.unite(i, j);
                int temp = next[j];  // Save next pointer
                next[j] = next[ub];  // Skip all nodes till upper bound
                j = temp;
            }
        }

        vector<bool> res;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            res.push_back(dsu.find(u) == dsu.find(v));
        }
        return res;
    }

public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
                                        return doPathExist(n,nums,maxDiff,queries);

                                      }
};