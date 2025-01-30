class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        int i = 0;
        int j = 1;
        while(j<s.length()){
            while(s[j]-s[j-1]==1){
                ans = max(ans,j-i+1);
                j++;
            }
            i = j;
            j = i+1;
        }
        return ans;
        
    }
};