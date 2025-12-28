// Last updated: 12/28/2025, 7:30:29 PM
1class Solution {
2public:
3    long long minimumCost(int cost1, int cost2, int costBoth,
4                          int need1, int need2) {
5
6        long long separate =
7            1LL * cost1 * need1 + 1LL * cost2 * need2;
8
9        int common = min(need1, need2);
10        long long mixed =
11            1LL * common * costBoth +
12            1LL * (need1 - common) * cost1 +
13            1LL * (need2 - common) * cost2;
14
15        long long onlyBundles =
16            1LL * max(need1, need2) * costBoth;
17
18        return min({separate, mixed, onlyBundles});
19    }
20};
21