// Last updated: 7/7/2025, 10:21:08 PM
class Solution {
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int f(int i,int tar,vector<vector<int>>& types){
        if(tar == 0) return 1;
        if(i == types.size() || tar<0) return 0;
        if(dp[tar][i]!=-1) return dp[tar][i];
        int ways = 0;
        int points = types[i][1];
        int maxQues = types[i][0];
        for(int k=0;k<=maxQues;k++){
            int pointsScore = k * points;
            if(pointsScore <= tar){
                ways = (ways + (f(i+1,tar-pointsScore,types)%mod))%mod;
            }else break;
        }

        return dp[tar][i] = ways;
    }
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        dp.resize(1001,vector<int>(51,-1));

        return f(0,target,types);
        
    }
};