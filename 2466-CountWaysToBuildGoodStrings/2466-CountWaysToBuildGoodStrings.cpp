class Solution {
    int mod = 10e8+7;
    vector<int> dp;
    int fun(int low,int high,int zero,int one,int len){
        if(len>high) return 0;
        if(dp[len] != -1) return dp[len];
        if(len>=low && len<=high){
            return dp[len] = (1 + fun(low,high,zero,one,len+zero) + fun(low,high,zero,one,len+one))%mod;
        }

        return dp[len] = (fun(low,high,zero,one,len+zero) + fun(low,high,zero,one,len+one))%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high+max(zero,one)+1,-1);
        return fun(low,high,zero,one,0);
        
    }
};