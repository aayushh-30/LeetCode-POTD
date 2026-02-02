// Last updated: 2/2/2026, 12:58:44 PM
1class Solution {
2    vector<int> getDist(int n,int src,vector<vector<int>> &adj){
3        vector<int> dist(n),vis(n,0);
4        queue<pair<int,int>> q;
5        q.push({src,0});
6        dist[src] = 0;
7        vis[src] = 1;
8
9        while(!q.empty()){
10            auto temp = q.front();
11            q.pop();
12            int cn = temp.first;
13            int cd = temp.second;
14
15            for(auto it:adj[cn]){
16                if(!vis[it]){
17                    vis[it] = 1;
18                    dist[it] = cd + 1;
19                    q.push({it,cd + 1});
20                }
21            }
22        }
23        return dist;
24
25    }
26public:
27    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
28        vector<vector<int>> adj(n);
29        for(auto it:edges){
30            int u = it[0];
31            int v = it[1];
32            adj[u].push_back(v);
33            adj[v].push_back(u);
34        }
35
36        vector<int> distX = getDist(n,x,adj);
37        vector<int> distY = getDist(n,y,adj);
38        vector<int> distZ = getDist(n,z,adj);
39        int cnt = 0;
40        for(int i=0;i<n;i++){
41            vector<int> dis;
42            dis.push_back(distX[i]);
43            dis.push_back(distY[i]);
44            dis.push_back(distZ[i]);
45            sort(dis.begin(),dis.end());
46            if((long long)dis[0]*dis[0] == (long long)dis[2]*dis[2] - (long long)dis[1]*dis[1]){
47                cnt++;
48            }
49        }
50
51        return cnt;
52
53        
54    }
55};