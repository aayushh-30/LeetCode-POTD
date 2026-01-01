// Last updated: 1/1/2026, 11:26:09 AM
1class Solution {
2public:
3    vector<int> addToArrayForm(vector<int>& A, int K) {
4    reverse(A.begin(), A.end());
5    for (int i = 0; i < A.size(); i++) {
6        A[i] += K;
7        K = A[i] / 10;
8        A[i] %= 10;
9    }
10    while (K) {
11        A.push_back(K%10);
12        K /= 10;
13    }
14    reverse(A.begin(), A.end());
15    return A;
16}
17};