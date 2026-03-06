// Last updated: 3/6/2026, 9:13:32 AM
1class Solution {
2    int comp(string s,string c){
3        int count = 0;
4        for(int i=0;i<s.length();i++){
5            if(s[i]!=c[i]){
6                count++;
7            }
8        }
9        return count;
10    }
11public:
12    int minOperations(string s) {
13        int n = s.length();
14        string opt1 = "",opt2 = "";
15        for(int i=0;i<n;i++){
16            if(i%2){
17                opt1 += '1';
18                opt2 += '0';
19            }else{
20                opt1 += '0';
21                opt2 += '1';
22            }
23
24        }
25
26        int op1 = comp(s,opt1);
27        int op2 = comp(s,opt2);
28
29        return min(op1,op2);
30
31
32        
33    }
34};