// Last updated: 11/16/2025, 6:15:39 PM
class Solution {
    #define MOD 1000000007
public:
    int numSub(string s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        long long ans = 0;
        while(j<n){
            while(s[i]==s[j]){
                j++;
            }
            long long len = j - i;
            if(s[i] == '1')
                ans = (ans + (len * (len + 1) / 2) % MOD) % MOD;
            i = j;
           
        }

        return ans;
        
        
    }
};