class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : roads) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            int d = it[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& it : adj[node]) {
                int nextNode = it.first;
                int edgeWeight = it.second;

                ans = min(ans, edgeWeight);

                if (!visited[nextNode]) {
                    visited[nextNode] = 1;
                    q.push(nextNode);
                }
            }
        }

        return ans;
    }
};
