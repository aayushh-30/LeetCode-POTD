// Last updated: 8/26/2025, 11:45:37 AM
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double diag = 0;
        int ans = 0;
        for(int i=0;i<dimensions.size();i++){
            double newDiag = sqrt((dimensions[i][0]*dimensions[i][0]) + (dimensions[i][1]*dimensions[i][1]));
            if(newDiag > diag){
                diag = newDiag;
                ans = dimensions[i][0] * dimensions[i][1];
            }else if(newDiag == diag){
                ans = max(ans,dimensions[i][0] * dimensions[i][1]);
            }
        }
        return ans;
        
    }
};