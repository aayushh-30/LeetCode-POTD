// Last updated: 12/15/2025, 11:56:15 PM
1class Solution {
2public:
3    long long getDescentPeriods(vector<int>& prices) {
4        long long total = 1;
5        long long cc = 1;
6        for(int i=1;i<prices.size();i++){
7            if(prices[i]-prices[i-1] == -1){
8                cc++;
9            }else{
10                cc = 1;
11            }
12            total += cc;
13        }
14
15        return total;
16        
17    }
18};