class Solution {
public:
vector<vector<int>> ans;
void solve(vector<int> &nums,int i,vector<int> &temp)
{
    if(i==nums.size())
    {
        ans.push_back(temp);
        return ;

    }
    temp.push_back(nums[i]);//take
    solve(nums,i+1,temp);//trust
    temp.pop_back();//not take
    while(i+1<nums.size() && nums[i]==nums[i+1])
    {
        i++;
    }
    solve(nums,i+1,temp);

    
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(nums,0,temp);
        return ans;
    }
};