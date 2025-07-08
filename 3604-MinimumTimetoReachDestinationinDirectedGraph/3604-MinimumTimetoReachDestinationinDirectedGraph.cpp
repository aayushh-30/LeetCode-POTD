// Last updated: 7/8/2025, 10:34:02 PM
class Solution {
    int f(vector<vector<vector<int>>> &adj, int n) {
        vector<int> Time(n, 1e9);
        queue<pair<int, int>> q; // node, currTime
        q.push({0, 0});
        Time[0] = 0;

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            int currNode = temp.first;
            int currTime = temp.second;

            for (auto &neighbour : adj[currNode]) {
                int nextNode = neighbour[0];
                int start = neighbour[1];
                int end = neighbour[2];

                if (currTime <= start) {
                    int reachTime = start + 1;
                    if (reachTime < Time[nextNode]) {
                        Time[nextNode] = reachTime;
                        q.push({nextNode, reachTime});
                    }
                } else if (currTime <= end) {
                    int reachTime = currTime + 1;
                    if (reachTime < Time[nextNode]) {
                        Time[nextNode] = reachTime;
                        q.push({nextNode, reachTime});
                    }
                }
            }
        }

        return Time[n - 1] == 1e9 ? -1 : Time[n - 1];
    }

public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> adj(n);
        for (auto &it : edges) {
            int u = it[0], v = it[1], start = it[2], end = it[3];
            adj[u].push_back({v, start, end});
        }

        return f(adj, n);
    }
};
