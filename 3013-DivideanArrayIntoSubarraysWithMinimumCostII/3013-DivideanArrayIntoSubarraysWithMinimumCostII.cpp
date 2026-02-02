// Last updated: 2/3/2026, 1:06:02 AM
1
2class Container {
3public:
4    Container(int k) : k(k), sm(0) {}
5
6    void adjust() {
7        while (st1.size() < k && st2.size() > 0) {
8            int x = *(st2.begin());
9            st1.emplace(x);
10            sm += x;
11            st2.erase(st2.begin());
12        }
13        while (st1.size() > k) {
14            int x = *prev(st1.end());
15            st2.emplace(x);
16            st1.erase(prev(st1.end()));
17            sm -= x;
18        }
19    }
20
21    void add(int x) {
22        if (!st2.empty() && x >= *(st2.begin())) {
23            st2.emplace(x);
24        } else {
25            st1.emplace(x);
26            sm += x;
27        }
28        adjust();
29    }
30
31    
32    void erase(int x) {
33        auto it = st1.find(x);
34        if (it != st1.end()) {
35            st1.erase(it), sm -= x;
36        } else {
37            st2.erase(st2.find(x));
38        }
39        adjust();
40    }
41
42    long long sum() { return sm; }
43
44private:
45    int k;
46 
47    multiset<int> st1, st2;
48   
49    long long sm;
50};
51
52class Solution {
53public:
54    long long minimumCost(vector<int>& nums, int k, int dist) {
55        int n = nums.size();
56        Container cnt(k - 2);
57        for (int i = 1; i < k - 1; i++) {
58            cnt.add(nums[i]);
59        }
60
61        long long ans = cnt.sum() + nums[k - 1];
62        for (int i = k; i < n; i++) {
63            int j = i - dist - 1;
64            if (j > 0) {
65                cnt.erase(nums[j]);
66            }
67            cnt.add(nums[i - 1]);
68            ans = min(ans, cnt.sum() + nums[i]);
69        }
70
71        return ans + nums[0];
72    }
73};