class Solution {
    class fun {
    public:
        vector<int> rank, parent;
        
        // Constructor to initialize DSU with `n` elements.
        fun(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        // Find function with path compression.
        int fp(int n) {
            if (n == parent[n]) return n;
            return parent[n] = fp(parent[n]);
        }

        // Union function with rank-based merging.
        void Union(int u, int v) {
            int pu = fp(u);
            int pv = fp(v);

            if (pu == pv) return;
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    };

    // Function to connect servers in the same row and column.
    void connectServers(vector<vector<int>>& grid, int r, int c, int m, int n, fun& f) {
        int node = r * n + c;  // Convert (r, c) into a unique node.
        
        // Connect servers in the same column.
        for (int i = 0; i < m; i++) {
            if (grid[i][c] == 1) {
                int newNode = i * n + c;
                f.Union(node, newNode);
            }
        }
        
        // Connect servers in the same row.
        for (int j = 0; j < n; j++) {
            if (grid[r][j] == 1) {
                int newNode = r * n + j;
                f.Union(node, newNode);
            }
        }
    }

public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        fun f(m * n);
        
        // Perform union operations for servers.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    connectServers(grid, i, j, m, n, f);
                }
            }
        }

        int totalServers = 0;
        int isolatedServers = 0;

        // Count total servers and isolated servers.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    totalServers++;
                    int node = i * n + j;
                    if (f.rank[f.fp(node)] == 0 && f.fp(node) == node) {
                        isolatedServers++;
                    }
                }
            }
        }

        // Subtract isolated servers from the total to get the count of communicative servers.
        return totalServers - isolatedServers;
    }
};
