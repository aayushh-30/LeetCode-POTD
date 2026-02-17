// Last updated: 2/17/2026, 9:25:47 AM
1class Solution {
2    int countBits(int n){
3        int cnt = 0;
4        while(n > 0){
5            cnt += (n & 1);
6            n >>= 1;
7        }
8        return cnt;
9    }
10
11public:
12    vector<string> readBinaryWatch(int turnedOn) {
13        vector<string> ans;
14
15        for(int h = 0; h < 12; h++){
16            for(int m = 0; m < 60; m++){
17                if(countBits(h) + countBits(m) == turnedOn){
18                    string time = to_string(h) + ":";
19                    
20                    if(m < 10)
21                        time += "0";
22                    
23                    time += to_string(m);
24                    ans.push_back(time);
25                }
26            }
27        }
28
29        return ans;
30    }
31};
32