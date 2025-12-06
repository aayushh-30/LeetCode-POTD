// Last updated: 12/6/2025, 8:27:29 PM
1class Solution {
2public:
3    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
4
5        int n = t1.size();
6        long long bestScore = 0;
7        vector<int> gain(n);
8
9        for(int i=0;i<n;i++){
10            bestScore += t2[i];
11            gain[i] = t1[i] - t2[i];
12        }
13
14        sort(gain.begin(),gain.end(),greater<int>());
15
16        for(int i=0;i<k;i++){
17            bestScore += gain[i];
18        }
19
20        for(int i=k;i<n && gain[i]>0;i++){
21            bestScore += gain[i];
22        }
23
24        return bestScore;
25        
26    }
27};