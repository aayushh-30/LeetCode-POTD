class Solution {
public:
    
    int find(int ind,vector<int>&nums,int tar)
    {
        if(ind==nums.size()-1)
        {
            return 0;
        }
        
        
        int ans=INT_MIN;
        
        for(int i=ind+1;i<nums.size();i++)
        {
            if(abs(nums[i]-nums[ind])<=tar) //checking  if we can jump to i
            {
                ans=max(ans,1+find(i,nums,tar)); // jump to i 
            }
        }
        return ans;
    }
    int maximumJumps(vector<int>& nums, int tar)
    {
       
        int ans=find(0,nums,tar);
       if(ans>0)
           return ans;
        else
            return -1;
    }
};