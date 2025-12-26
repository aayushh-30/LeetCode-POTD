// Last updated: 12/26/2025, 1:54:40 PM
1class Solution {
2public:
3    int bestClosingTime(string customers) {
4        int n = customers.length();
5        vector<int> prefixN(n+1,0);
6        vector<int> suffixY(n+1,0);
7        int cnt = 0;
8        for(int i=1;i<n+1;i++){
9            if(customers[i-1]=='N') cnt++;
10            prefixN[i] = cnt;
11            
12        }
13        cnt = 0;
14        for(int i=n-1;i>=0;i--){
15            if(customers[i]=='Y') cnt++;
16            suffixY[i] = cnt;
17        }
18
19        int Sum = INT_MAX;
20        int ans = INT_MAX;
21        for(int i=n;i>=0;i--){
22            if(prefixN[i]+suffixY[i]<= Sum){
23                ans = i;
24                Sum = prefixN[i]+suffixY[i];
25            }
26        }
27        return ans;
28
29
30        
31    }
32};