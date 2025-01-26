class Solution {
public:
    int dfs(int node, vector<int>& edges, vector<int>& vis, vector<int>& stackDist, int currDist) {
        if (node == -1) return -1; // No outgoing edge
        if (vis[node] == 2) return -1; // Node already fully processed
        if (vis[node] == 1) {
            // Cycle detected
            return currDist - stackDist[node];
        }

        // Mark node as visiting
        vis[node] = 1;
        stackDist[node] = currDist;

        // Recur to the next node
        int cycleLength = dfs(edges[node], edges, vis, stackDist, currDist + 1);

        // Mark node as fully processed
        vis[node] = 2;
        return cycleLength;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);         // 0 = unvisited, 1 = visiting, 2 = processed
        vector<int> stackDist(n, -1); // Distance of each node in the current DFS stack
        int maxCycleLength = -1;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                maxCycleLength = max(maxCycleLength, dfs(i, edges, vis, stackDist, 0));
            }
        }

        return maxCycleLength;
    }
};
