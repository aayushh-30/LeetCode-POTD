// Last updated: 6/5/2025, 7:17:12 AM
class Solution {
    char dfs(char s,map<char,vector<char>> &adj,vector<int> &vis){
        char minChar = s;
        vis[s-'a'] = 1;
        for(auto it:adj[s]){
            if(vis[it-'a']==0){
                minChar = min(minChar,dfs(it,adj,vis));
            }
        }
        return minChar;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        map<char,vector<char>> adj;
        for(int i=0;i<n;i++){
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string ans = "";
        for(int i=0;i<baseStr.length();i++){
            vector<int> vis(26,0);
            char mini = dfs(baseStr[i],adj,vis);
            ans+=mini;

        }
        return ans;

        
    }
};