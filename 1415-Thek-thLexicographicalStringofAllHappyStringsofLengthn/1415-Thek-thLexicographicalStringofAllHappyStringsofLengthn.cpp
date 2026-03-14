// Last updated: 3/14/2026, 9:47:14 AM
1class Solution {
2    vector<string> ans;
3    void fun(string &s,string temp,int n){
4        if(temp.length() == n){
5            ans.push_back(temp);
6            return;
7        }
8
9        for(int i=0;i<3;i++){
10            if(temp.size()==0 || temp.back()!=s[i]){
11                temp.push_back(s[i]);
12                fun(s,temp,n);
13                temp.pop_back();
14            }
15        }
16
17    }
18public:
19    string getHappyString(int n, int k) {
20        string s = "abc";
21        fun(s,"",n);
22        if(k>ans.size()) return "";
23        return ans[k-1];
24        
25    }
26};