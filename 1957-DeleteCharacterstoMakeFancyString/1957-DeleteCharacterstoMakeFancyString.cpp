// Last updated: 7/21/2025, 9:06:05 AM
class Solution {
public:
    string makeFancyString(string s) {
        s+='A';
        int cnt = 1;
        string ans = "";
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                cnt = 1;
            }

            if(cnt<=2){
                ans+=s[i-1];
            }
        }
        return ans;
        
    }
};