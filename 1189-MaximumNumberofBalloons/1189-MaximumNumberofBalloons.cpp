// Last updated: 6/22/2026, 11:23:33 AM
1class Solution {
2    bool canMadeBaloon(vector<int> &alpha){
3        return alpha['b'-'a'] >= 1 && alpha['a'-'a'] >= 1 && alpha['l'-'a'] >= 2 && alpha['o'-'a']>=2 && alpha['n'-'a'] >= 1;
4    }
5public:
6    int maxNumberOfBalloons(string text) {
7        vector<int> alpha(26,0);
8        for(int i=0;i<text.length();i++){
9            alpha[text[i]-'a']++;
10        }
11        int ans = 0;
12        while(canMadeBaloon(alpha)){
13            ans++;
14            string name = "balloon";
15            for(int i=0;i < 7;i++ ){
16                alpha[name[i]-'a']--;
17            }
18        }
19
20        return ans;
21        
22    }
23};