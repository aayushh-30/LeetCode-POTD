class Solution {
    #define MOD 1000000007
    unordered_map<string,int> mp;
    int fun(int cr,int cc,int m,int n,int maxM){
         if(cr>=m || cr<0 || cc<0 || cc >= n){
                return 1;
            }
        if(maxM == 0){
            return 0;
        }
        string key = to_string(cr)+','+to_string(cc)+','+to_string(maxM);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }

        int up = fun(cr + 1,cc,m,n,maxM-1)%MOD;
        int down = fun(cr - 1,cc,m,n,maxM-1)%MOD;
        int left = fun(cr,cc-1,m,n,maxM-1)%MOD;
        int right = fun(cr,cc+1,m,n,maxM-1)%MOD;

        return mp[key] = ((up+down) % MOD +(left+right) %MOD)%MOD;


    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        int ans = fun(startRow,startColumn,m,n,maxMove);

        return ans;
        
    }
};