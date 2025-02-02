class Solution {
    class DSU{
        public:
        vector<int> parent, size;
        DSU(int n){
            parent.resize(n);
            size.resize(n, 1);
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int findParent(int u){
            if(parent[u] == u) return u;
            return parent[u] = findParent(parent[u]);
        }

        void Union(int u, int v){
            int p_u = findParent(u);
            int p_v = findParent(v);

            if(p_u == p_v) return;

            if(size[p_u] < size[p_v]){
                parent[p_u] = p_v;
                size[p_v] += size[p_u];
            } else {
                parent[p_v] = p_u;
                size[p_u] += size[p_v];
            }
        }
    };

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DSU ds(n);
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            ds.Union(u, v);
        }

        unordered_map<int, vector<int>> components;
        for(int i = 0; i < n; i++){
            components[ds.findParent(i)].push_back(i);
        }

        int ans = 0;
        for(auto &[leader, nodes] : components){
            bool canBeCounted = true;
            for(int node : nodes){
                if(adj[node].size() != nodes.size() - 1){
                    canBeCounted = false;
                    break;
                }
            }
            if(canBeCounted) ans++;
        }

        return ans;
    }
};
