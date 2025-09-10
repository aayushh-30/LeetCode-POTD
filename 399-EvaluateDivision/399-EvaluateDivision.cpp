// Last updated: 9/10/2025, 1:12:46 PM
class Solution {
    double fun(string u,string v,unordered_map<string,vector<pair<string,double>>> &adj){
        if(adj.find(u) == adj.end() || adj.find(v) == adj.end()) return -1;
        int n = adj.size();
        unordered_map<string,int> vis;
        vis[u] = 1;
        queue<pair<string,double>> q;
        q.push({u,1});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            string currNode = temp.first;
            double val = temp.second;
            if(currNode == v) return val;
            for(auto it:adj[currNode]){
                if(vis.find(it.first) == vis.end()){
                    q.push({it.first,val * it.second});
                    vis[it.first] = 1;
                }
            }
        }

        return -1.000;

    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1/(values[i])});
        }

        // for(auto it:adj){
        //     cout<<it.first<<"-->";
        //     for(auto num:it.second){
        //         cout<<num.first<<num.second<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<double> ans;
        for(auto query : queries){
            string u = query[0];
            string v = query[1];

            double res = fun(u,v,adj);
            ans.push_back(res);

        }

        return ans;
        
    }
};