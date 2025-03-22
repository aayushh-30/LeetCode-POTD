// Last updated: 3/23/2025, 12:00:23 AM
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(n + 1, 0);
        vector<int> dp(n + 1, 0); // To store cumulative time for each course

        // Build graph and calculate in-degrees
        for (auto& it : relations) {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                dp[i] = time[i - 1];
            }
        }

        int totalTime = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            totalTime = max(totalTime, dp[curr]);

            for (auto& next : graph[curr]) {
                dp[next] = max(dp[next], dp[curr] + time[next - 1]);
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return totalTime;
    }
};
