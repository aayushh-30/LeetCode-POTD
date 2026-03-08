// Last updated: 3/8/2026, 7:21:35 PM
1class Solution {
2    string res = "";
3    void fun(string temp,int n,unordered_set<string> &st){
4        if(temp.length() == n){
5            if(st.find(temp) == st.end()){
6                res = temp;
7            }
8            return;
9        }
10
11        fun(temp+'0',n,st);
12        fun(temp+'1',n,st);
13    }
14public:
15    string findDifferentBinaryString(vector<string>& nums) {
16        unordered_set<string> st(nums.begin(),nums.end());
17        int n = nums.size();
18        string temp = "";
19        fun(temp,n,st);
20        return res;
21
22        
23    }
24};