// Last updated: 1/4/2026, 1:30:52 PM
1class Solution {
2    void buildSeive(int n, vector<int>& count, vector<int>& sum) {
3        for (int i = 1; i * i <= n; ++i) {
4            for (int j = i * i; j <= n; j += i) {
5                count[j]++;
6                sum[j] += i;
7
8                if (i != j / i) {
9                    count[j]++;
10                    sum[j] += j / i;
11                }
12            }
13        }
14    }
15
16public:
17    int sumFourDivisors(vector<int>& nums) {
18        int maxi = *max_element(nums.begin(), nums.end());
19
20        vector<int> count(maxi + 1, 0);
21        vector<int> sum(maxi + 1, 0);
22
23        buildSeive(maxi, count, sum);
24
25        int res = 0;
26        for (int x : nums) {
27            if (count[x] == 4)
28                res += sum[x];
29        }
30        return res;
31    }
32};
33