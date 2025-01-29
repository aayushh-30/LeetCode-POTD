class Solution {
    class fun{
        public:
        vector<int> rank,parent;
        fun(int n){
            rank.resize(n,0);
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i] = i;
        }

        int find_parent(int n){
            if(parent[n]==n) return n;
            return parent[n] = find_parent(parent[n]);
        }

        void Union(int u,int v){
            int pu = find_parent(u);
            int pv = find_parent(v);

            if(rank[pu]<rank[pv]){
                parent[pu] = pv;
            }else if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }else{
                parent[pv] = pu;
                rank[pv]++;
            }
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2);
        fun f(edges.size()+1);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int parent_u = f.find_parent(u);
            int parent_v = f.find_parent(v);
            if(parent_u==parent_v){
                ans[0] = u;
                ans[1] = v;
            }else{
                f.Union(u,v);
            }
        }

        return ans;
        
    }
};