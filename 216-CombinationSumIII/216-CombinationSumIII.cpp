class Solution {
    vector<vector<int>> ans;
    void fun(int i,int k,int n,vector<int> temp){
        if(n==0 && k == 0){
            ans.push_back(temp);
            return;
        }
        if(i<1||i>9) return;
        if(k<0 || n<0) return;
        
        

        fun(i+1,k,n,temp);
        temp.push_back(i);
        fun(i+1,k-1,n-i,temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        fun(1,k,n,{});
        return ans;
        
    }
};