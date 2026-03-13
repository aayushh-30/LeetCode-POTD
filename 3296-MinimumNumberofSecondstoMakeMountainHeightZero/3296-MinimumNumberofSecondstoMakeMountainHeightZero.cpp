// Last updated: 3/14/2026, 12:11:30 AM
1class Solution {
2public:
3    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
4        int maxWorkerTimes =
5            *max_element(workerTimes.begin(), workerTimes.end());
6        long long l = 1, r = static_cast<long long>(maxWorkerTimes) *
7                             mountainHeight * (mountainHeight + 1) / 2;
8        long long ans = 0;
9
10        while (l <= r) {
11            long long mid = (l + r) / 2;
12            long long cnt = 0;
13            for (int t : workerTimes) {
14                long long work = mid / t;
15                
16                long long k = (-1.0 + sqrt(1 + work * 8)) / 2 + eps;
17                cnt += k;
18            }
19            if (cnt >= mountainHeight) {
20                ans = mid;
21                r = mid - 1;
22            } else {
23                l = mid + 1;
24            }
25        }
26
27        return ans;
28    }
29
30private:
31    static constexpr double eps = 1e-7;
32};