// Last updated: 1/7/2026, 12:23:38 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12#define mod 1000000007
13
14class Solution {
15    long long totalSum(TreeNode* root) {
16        if (!root) return 0;
17        return root->val + totalSum(root->left) + totalSum(root->right);
18    }
19
20    long long dfs(TreeNode* root, long long total, long long &ans) {
21        if (!root) return 0;
22
23        long long left = dfs(root->left, total, ans);
24        long long right = dfs(root->right, total, ans);
25
26        long long sub = left + right + root->val;
27        ans = max(ans, sub * (total - sub));
28
29        return sub;
30    }
31
32public:
33    int maxProduct(TreeNode* root) {
34        long long total = totalSum(root);
35        long long ans = 0;
36        dfs(root, total, ans);
37        return ans % mod;
38    }
39};
40