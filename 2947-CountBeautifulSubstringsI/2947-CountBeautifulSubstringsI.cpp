// Last updated: 6/17/2026, 11:50:04 AM
1class Solution {
2public:
3    unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
4    bool isVowel(char c) { return st.find(c) != st.end(); }
5    int beautifulSubstrings(string s, int k) {
6        int ans = 0;
7        for(int i = 0; i < s.size(); ++i){
8            int vow = 0, con = 0;
9            for(int j = i; j < s.size(); ++j) {
10                (isVowel(s[j]))? vow++: con++;
11                if(vow == con && (vow*con)%k == 0) ans++;
12            }
13        }
14        return ans;
15    }
16};