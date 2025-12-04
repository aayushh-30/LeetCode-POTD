// Last updated: 12/4/2025, 11:27:52 PM
1class Solution {
2public:
3    int countCollisions(string directions) {
4        int n = directions.length();
5        int i = 0;
6        int j = n-1;
7        while(i<n && directions[i] == 'L'){
8            i++;
9        }
10        while(j>=0 && directions[j] == 'R'){
11            j--;
12        }
13
14        int ans = 0;
15        for(int k=i;k<=j;k++){
16            if(directions[k]!='S') ans++;
17        }
18
19        return ans;
20        
21    }
22};