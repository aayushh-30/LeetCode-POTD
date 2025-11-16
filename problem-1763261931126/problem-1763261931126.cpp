// Last updated: 11/16/2025, 8:28:51 AM
class Solution {
public:
    long long dp[20][2][2];
    string s;
    long long ak;
    long long fun(int pos,bool tig,bool st){
        if(pos == s.size()){
            return st ? 1 : 0;
        }

        long long &res = dp[pos][tig][st];
        if(res != -1) return res;

        res = 0;
        int limit = tig ? s[pos] -'0' : 9;

        for(int d = 0;d<= limit;d++){
            bool ntig = (tig && (d == limit));
            bool nst = (st||d != 0);

            if(nst && d == 0) continue;

            res += fun(pos+1,ntig,nst);
        }
        return res;
    }
    long long countDistinct(long long n) {
        ak = n;
        s = to_string(ak);
        memset(dp,-1,sizeof(dp));
        return fun(0,true,false);
        
        
    }
};