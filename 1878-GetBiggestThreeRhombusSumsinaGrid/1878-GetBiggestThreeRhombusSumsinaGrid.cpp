// Last updated: 3/16/2026, 11:52:37 PM
1struct Answer {
2    array<int, 3> ans{};
3
4    void put(int x) {
5        if (x > ans[0]) {
6            tie(ans[0], ans[1], ans[2]) = tuple{x, ans[0], ans[1]};
7        } else if (x != ans[0] && x > ans[1]) {
8            tie(ans[1], ans[2]) = tuple{x, ans[1]};
9        } else if (x != ans[0] && x != ans[1] && x > ans[2]) {
10            ans[2] = x;
11        }
12    }
13
14    vector<int> get() const {
15        vector<int> ret;
16        for (int num : ans) {
17            if (num) {
18                ret.push_back(num);
19            }
20        }
21        return ret;
22    }
23};
24
25class Solution {
26public:
27    vector<int> getBiggestThree(vector<vector<int>>& grid) {
28        int m = grid.size(), n = grid[0].size();
29        vector<vector<int>> sum1(m + 1, vector<int>(n + 2));
30        vector<vector<int>> sum2(m + 1, vector<int>(n + 2));
31        for (int i = 1; i <= m; ++i) {
32            for (int j = 1; j <= n; ++j) {
33                sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];
34                sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];
35            }
36        }
37        Answer ans;
38        for (int i = 0; i < m; ++i) {
39            for (int j = 0; j < n; ++j) {
40                // a single cell is also a rhombus
41                ans.put(grid[i][j]);
42                for (int k = i + 2; k < m; k += 2) {
43                    int ux = i, uy = j;
44                    int dx = k, dy = j;
45                    int lx = (i + k) / 2, ly = j - (k - i) / 2;
46                    int rx = (i + k) / 2, ry = j + (k - i) / 2;
47                    if (ly < 0 || ry >= n) {
48                        break;
49                    }
50                    ans.put((sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]) +
51                            (sum1[rx + 1][ry + 1] - sum1[ux][uy]) +
52                            (sum1[dx + 1][dy + 1] - sum1[lx][ly]) +
53                            (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) -
54                            (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] +
55                             grid[rx][ry]));
56                }
57            }
58        }
59        return ans.get();
60    }
61};