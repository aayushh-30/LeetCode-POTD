// Last updated: 2/22/2026, 10:51:33 AM
1class Solution {
2public:
3    int binaryGap(int n) {
4        int start=-1,end=-1;
5        int ans=0;
6
7        for(int i=0;i<32;i++){
8            int d=(n>>i) & 1;
9            if(d){
10                start=(start==-1)?i:start;
11                end=(end==-1)?start:i;
12                ans=max(ans,end-start);
13                start=end;
14            }
15        }
16
17        return ans;
18    }
19};