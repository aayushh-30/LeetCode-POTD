// Last updated: 12/24/2025, 11:59:40 PM
1class Solution {
2public:
3    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
4        int sum = accumulate(apple.begin(), apple.end(), 0);
5        sort(capacity.begin(), capacity.end(), greater<int>());
6
7        int need = 0;
8        while (sum > 0) {
9            sum -= capacity[need];
10            need += 1;
11        }
12
13        return need;
14    }
15};