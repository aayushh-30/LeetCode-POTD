class Solution {
    #define ll long long
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long row1 = accumulate(grid[0].begin(),grid[0].end(),0ll);
        ll ans = LONG_LONG_MAX;
        ll row2 = 0;
        for(int i=0;i<grid[0].size();i++){
            row1 -= grid[0][i];
            ans = min(ans,max(row1,row2));
            row2+=grid[1][i];
        }

        return ans;
    }
};