// Last updated: 11/16/2025, 8:16:24 AM
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnt = 0;
        int unb = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'a'){
                cnt++;
            }else{
                unb++;
            }
        }
        return abs(cnt-unb);
        
    }
};