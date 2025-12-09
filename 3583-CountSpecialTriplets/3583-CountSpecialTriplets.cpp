// Last updated: 12/9/2025, 10:56:46 AM
1class Solution {
2    #define mod 1000000007
3    typedef long long ll;
4public:
5    int specialTriplets(vector<int>& nums) {
6        unordered_map<int,int> prevFreq, totalFreq;
7        
8        for(int x : nums) totalFreq[x]++;
9
10        ll cnt = 0;
11        for(int x : nums) {
12            totalFreq[x]--;
13            int target = x * 2;
14
15            if(prevFreq.count(target) && totalFreq.count(target)) {
16                ll ways = (1LL * prevFreq[target] % mod) * (totalFreq[target] % mod) % mod;
17                cnt = (cnt + ways) % mod;
18            }
19
20            prevFreq[x]++;
21        }
22        return cnt;
23    }
24};
25