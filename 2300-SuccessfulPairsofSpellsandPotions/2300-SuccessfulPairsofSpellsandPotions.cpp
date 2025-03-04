class Solution {
    int fun(vector<int> &spells,int val,long long success){
        int n = spells.size();
        int i = 0;
        int j = spells.size() - 1;
        int maxLen = 0;
        while(i<=j){
            int mid = i + (j-i)/2;
            long long value = (long long)spells[mid] * (long long)val; 
            if(value >= success ){
                maxLen = max(maxLen,n - mid);
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }

        return maxLen;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int subAns = fun(potions,spells[i],success);
            ans.push_back(subAns);
        }
        return ans;
    }
};