// Last updated: 2/21/2026, 1:41:46 PM
1class Solution {
2    vector<int> arr;
3
4    void fun(){   // 1 = non-prime
5        arr.assign(1e6+1, 0);
6        arr[0] = arr[1] = 1;
7
8        for (int i = 2; i * i <= 1e6; i++) {
9            if (arr[i] == 0) {
10                for (int j = i * i; j <= 1e6; j += i) {
11                    arr[j] = 1;
12                }
13            }
14        }
15    }
16
17    int countBits(int n){
18        int c = 0;
19        while(n){
20            c += (n & 1);
21            n >>= 1;
22        }
23        return c;
24    }
25
26public:
27    int countPrimeSetBits(int left, int right) {
28        fun();
29        int ans = 0;
30
31        for(int i = left; i <= right; i++){
32            int cb = countBits(i);
33            if(arr[cb] == 0) ans++;
34        }
35        return ans;
36    }
37};