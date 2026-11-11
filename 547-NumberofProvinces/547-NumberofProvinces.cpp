// Last updated: 11/11/2026, 11:28:36 PM
1class Solution {
2    void letsVisit(vector<int> &vis, vector<vector<int>> &adj, int node){
3        vis[node] = 1;
4        for(auto it:adj[node]){
5            if(vis[it]!=1){
6                letsVisit(vis,adj,it);
7            }
8        }
9
10    }
11public:
12    int findCircleNum(vector<vector<int>>& isConnected) {
13        int n = isConnected.size();
14        vector<vector<int>> adjList(n);
15        for(int i=0;i<n;i++){
16            for(int j=0;j<n;j++){
17                if(i != j && isConnected[i][j] == 1){
18                    adjList[i].push_back(j);
19                    adjList[j].push_back(i);
20                }
21            }
22        }
23
24        vector<int> vis(n,0);
25
26        int ans = 0;
27        for(int i=0;i<n;i++){
28            if(vis[i]!=1){
29                ans++;
30                letsVisit(vis,adjList,i);
31            }
32        }
33
34        return ans;
35
36        
37    }
38};