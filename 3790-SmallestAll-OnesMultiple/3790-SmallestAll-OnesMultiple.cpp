// Last updated: 12/28/2025, 7:47:51 PM
1class Solution {
2public:
3    int minAllOneMultiple(int k) {
4        unordered_set<int> st;
5        int num = 1;
6        int cnt = 1;
7        while(st.find(num%k)==st.end()){
8            st.insert(num % k);
9            num = (((num%k)*10)%k+1)%k;
10            cnt++;
11            if(num%k==0){
12                return cnt;
13            }
14        }
15
16        return -1;
17        
18    }
19};