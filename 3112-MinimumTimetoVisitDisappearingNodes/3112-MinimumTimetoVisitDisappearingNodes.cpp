// Last updated: 4/26/2025, 5:12:40 PM
class Solution {
    vector<int> fun(vector<vector<int>> edges, int n, vector<int> disappear) {

        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int d = it[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<int> distance(n, 1e9);

        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> q;

        // distance,node
            q.push({0, 0});
            distance[0] = 0;

        while (!q.empty()) {
            auto temp = q.top();
            q.pop();

            int dist = temp.first;
            int node = temp.second;

            if(distance[node] != dist) continue;

            for (auto it : adj[node]) {
                if (dist + it.second < distance[it.first] &&
                    dist + it.second < disappear[it.first]) {
                    distance[it.first] = dist + it.second;
                    q.push({ dist+it.second,it.first});
                }
            }
        }

        for (int i = 0; i < distance.size(); i++) {
            if (distance[i] == 1e9) {
                distance[i] = -1;
            }
        }

        return distance;
    }

public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges,
                            vector<int>& disappear) {

        return fun(edges, n, disappear);
    }
};