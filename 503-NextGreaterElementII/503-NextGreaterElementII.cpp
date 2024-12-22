class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        int lastIndex = 2 * n - 1;
        stack<int> st;
        for(int i = lastIndex ; i>=0 ;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(!st.empty() && i<n){
                ans[i] = st.top();
            }
            st.push(nums[i%n]);

        }
        return ans;
        
    }
};