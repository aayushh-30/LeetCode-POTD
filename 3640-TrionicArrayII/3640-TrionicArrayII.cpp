// Last updated: 2/4/2026, 11:07:06 PM
1
2class Solution {
3public:
4    vector<tuple<int, int, long long> > decompose(vector<int>& nums){
5        int n = (int)nums.size();
6        vector<tuple<int, int, long long> > subarrays;
7
8        int l = 0;
9        long long sum = nums[0];
10        
11        for(int i = 1; i < n; i ++){
12           
13            if(nums[i - 1] <= nums[i]){
14                subarrays.push_back({l, i - 1, sum});
15                l = i;
16                sum = 0;
17            }
18            sum += nums[i];
19        }
20        
21        subarrays.push_back({l, n - 1, sum});
22        return subarrays;
23    }
24    long long maxSumTrionic(vector<int>& nums){
25        int n = (int)nums.size();
26        long long maxEndingAt[n];
27        for(int i = 0; i < n; i ++){
28            maxEndingAt[i] = nums[i];
29            if(i > 0 && nums[i - 1] < nums[i]){
30                if(maxEndingAt[i - 1] > 0){
31                    maxEndingAt[i] += maxEndingAt[i - 1];
32                }
33            }
34        }
35        long long maxStartingAt[n];
36        for(int i = n - 1; i >= 0; i --){
37            maxStartingAt[i] = nums[i];
38            if(i < n - 1 && nums[i] < nums[i + 1]){
39                if(maxStartingAt[i + 1] > 0){
40                    maxStartingAt[i] += maxStartingAt[i + 1];
41                }
42            }
43        }
44        vector<tuple<int, int, long long> > PQS = decompose(nums);
45        long long ans = LLONG_MIN;
46        for(auto [p, q, sum] : PQS){
47            
48            if(p > 0 && nums[p-1] < nums[p] &&
49               q < n - 1 && nums[q] < nums[q + 1] &&
50               p < q){
51                ans = max(ans, maxEndingAt[p-1] + sum + maxStartingAt[q+1]);
52            }
53        }
54        return ans;
55    }
56};