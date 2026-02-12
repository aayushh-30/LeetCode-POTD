// Last updated: 2/12/2026, 10:47:00 AM
1class Solution {
2    bool fun(vector<int> &freq){
3        int lastSeen = 0;
4        for(int i=0;i<26;i++){
5            if(freq[i] == 0) continue;
6            if(lastSeen != 0 && freq[i] != lastSeen) return false;
7            lastSeen = freq[i];
8        }
9        return true;
10
11    }
12public:
13    int longestBalanced(string s) {
14        vector<int> freq(26,0);
15        int n = s.length();
16        if(n == 1) return 1;
17        int ans = 0;
18        for(int i=0;i<n;i++){
19            string sub = "";
20            sub += s[i];
21            freq[s[i]-'a']++;
22            for(int j=i+1;j<n;j++){
23                sub += s[j];
24                freq[s[j]-'a']++;
25                if(fun(freq)){
26                    ans = max(ans,j - i + 1);
27                }
28            }
29            freq.clear();
30            freq.resize(26,0);
31        }
32        return ans;
33        
34    }
35};