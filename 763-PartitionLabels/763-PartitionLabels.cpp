// Last updated: 3/30/2025, 10:39:50 AM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        for(int i=0;i<s.length();i++){
            last[s[i]] = i;
        }

        int i = 0;
        int j = 0;
        int k = 0;
        vector<int> vis(26,0);
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            if(vis[s[i]-'a'] == 0){
                vis[s[i]-'a'] = 1;
                k = max(k,last[s[i]]);
            }
            if(i == k){
                ans.push_back(k-j+1);
                j = i+1;
            }
            
        }
        return ans;

        
    }
};