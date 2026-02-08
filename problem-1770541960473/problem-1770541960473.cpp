// Last updated: 2/8/2026, 2:42:40 PM
1class Solution {
2public:
3    vector<long long> mergeAdjacent(vector<int>& nums) {
4        stack<long long> st;
5        for(int i=0;i<nums.size();i++){
6            if(st.empty() || st.top() != nums[i]){
7                st.push(nums[i]);
8            }else{
9                long long newEl = nums[i];
10                while(!st.empty() && st.top() == newEl){
11                    st.pop();
12                    newEl *= 2;
13                }
14                st.push(newEl);
15                
16            }
17        }
18
19        vector<long long> ans;
20        while(!st.empty()){
21            ans.push_back(st.top());
22            st.pop();
23        }
24
25        reverse(ans.begin(),ans.end());
26        return ans;
27        
28    }
29};