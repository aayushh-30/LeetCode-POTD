// Last updated: 2/12/2026, 12:46:22 AM
1struct Node {
2    short min, max, lazy;
3    Node():min(SHRT_MAX), max(SHRT_MIN), lazy(0) {}
4    Node(int x): min(x), max(x), lazy(0) {}
5};
6
7class SegmentTree {
8public:
9    vector<Node> segTree;
10    unsigned n;
11
12    SegmentTree(vector<int>& arr) {
13        n=arr.size();
14        
15        segTree.assign(n<<2, Node());
16        buildTree(1, 0, n-1, arr);
17    }
18
19    void pull(int i) {
20        segTree[i].min=min(segTree[2*i].min, segTree[2*i+1].min);
21        segTree[i].max=max(segTree[2*i].max, segTree[2*i+1].max);
22    }
23
24    void buildTree(int i, int l, int r, vector<int>& arr) {
25        if (l==r) {
26            segTree[i]=Node(arr[l]);
27            return;
28        }
29        int m=(l+r)>>1;
30        buildTree(2*i, l, m, arr);
31        buildTree(2*i+1, m+1, r, arr);
32        pull(i);
33    }
34
35    void apply(int i, int l, int r) {
36        if (segTree[i].lazy==0) return;
37        segTree[i].min+=segTree[i].lazy;
38        segTree[i].max+=segTree[i].lazy;
39        if (l<r) {
40            segTree[2*i].lazy+=segTree[i].lazy;
41            segTree[2*i+1].lazy+=segTree[i].lazy;
42        }
43        segTree[i].lazy=0;
44    }
45
46    void updateRange(int start, int end, int i, int l, int r, int val) {
47        apply(i, l, r);
48        if (l>end || r<start) return;
49
50        if (l>=start && r<=end) {
51            segTree[i].lazy+= val;
52            apply(i, l, r);
53            return;
54        }
55
56        int m=(l+r)>>1;
57        updateRange(start, end, 2*i, l, m, val);
58        updateRange(start, end, 2*i+1, m+1, r, val);
59        pull(i);
60    }
61
62    int findLast0(int i, int l, int r) {
63        apply(i, l, r);
64        
65        if (segTree[i].min>0|| segTree[i].max<0) return -1;
66
67        if (l==r) return l;
68
69        int m=(l+r)>>1;
70    
71        int right=findLast0(2*i+1, m+1, r);
72        if (right!=-1) return right;
73        return findLast0(2*i, l, m);
74    }
75};
76
77constexpr int N=1e5+1;
78bitset<N> seen=0;
79class Solution {
80public:
81    static int longestBalanced0(vector<int>& nums) {
82        const int n=nums.size();
83        int len=0;
84        for(int l=0; l<n; l++){
85            if (l>n-len) break;
86            int diff=0;
87            for(int r=l; r<n; r++){
88                const int x=nums[r];
89                if (!seen[x]) {diff+=(1-(x&1)*2), seen[x]=1; }
90                if (diff==0)
91                    len=max(len, r-l+1);
92            }
93            for(int i=l; i<n; i++) seen[nums[i]]=0;
94        }
95        return len;
96    }
97    static int longestBalanced(vector<int>& nums) {
98        const int n=nums.size();
99        if (n<=2000) return longestBalanced0(nums);
100
101        const int M=*max_element(nums.begin(), nums.end());
102        vector<int> last(M+1, n);
103        vector<int> nextPos(n, n);
104        for (int i=n-1; i>= 0; i--) {
105            const int x=nums[i];
106            nextPos[i]=last[x];
107            last[x]=i;
108        }
109
110        
111        vector<int> prefix(n);
112        int sum=0;
113        for (int i=0; i<n; i++) {
114            const int x=nums[i];
115            if (!seen[x]) {
116                sum+=(x&1)?1:-1;
117                seen[x]=1;
118            }
119            prefix[i]=sum;
120        }
121       
122        for(int i=0; i<n; i++) seen[nums[i]]=0;
123
124        SegmentTree seg(prefix);
125        
126        int ans=seg.findLast0(1, 0, n-1)+1;
127
128        for (int i=0; i<n-1; i++) {
129            int r=nextPos[i]-1;
130            
131            if (i+1<=r) {
132                int val=(nums[i] & 1)?-1:1;
133                seg.updateRange(i+1, r, 1, 0, n-1, val);
134            }
135
136            
137            if (i+ans+1<n) {
138                int right=seg.findLast0(1, 0, n-1);
139                if (right!=-1) 
140                    ans=max(ans, right-i);
141            }
142        }
143        return ans;
144    }
145};
146auto init = []() {
147    ios::sync_with_stdio(0);
148    cin.tie(0);
149    cout.tie(0);
150    return 'c';
151}();