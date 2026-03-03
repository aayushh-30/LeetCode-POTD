// Last updated: 3/3/2026, 10:05:47 AM
1class Solution {
2    string invert(string s){
3        for(int it=0;it<s.length();it++){
4            if(s[it]=='0'){
5                s[it] = '1';
6            }else{
7                s[it] = '0';
8            }
9        }
10        return s;
11
12    }
13    char fun(int i,int n,int k,string s){
14        if(i==n){
15            return s[k-1];
16        }
17        string cp = invert(s);
18        reverse(cp.begin(),cp.end());
19        string newS = s +'1'+ cp;
20        return fun(i+1,n,k,newS);
21
22    }
23public:
24    char findKthBit(int n, int k) {
25        string s = "0";
26        char ans = fun(1,n,k,s);
27        return ans;
28        
29    }
30};