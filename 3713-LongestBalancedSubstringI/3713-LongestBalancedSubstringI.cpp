// Last updated: 10/12/2025, 6:53:18 PM
class Solution {
    bool fun(vector<int> &freq){
        int lastSeen = 0;
        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            if(lastSeen != 0 && freq[i] != lastSeen) return false;
            lastSeen = freq[i];
        }
        return true;

    }
public:
    int longestBalanced(string s) {
        vector<int> freq(26,0);
        int n = s.length();
        if(n == 1) return 1;
        int ans = 0;
        for(int i=0;i<n;i++){
            string sub = "";
            sub += s[i];
            freq[s[i]-'a']++;
            for(int j=i+1;j<n;j++){
                sub += s[j];
                freq[s[j]-'a']++;
                if(fun(freq)){
                    ans = max(ans,j - i + 1);
                }
            }
            freq.clear();
            freq.resize(26,0);
        }
        return ans;
        
    }
};