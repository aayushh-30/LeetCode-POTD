// Last updated: 2/9/2026, 11:33:50 PM
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
12class Solution {
13public:
14    void inorder(TreeNode* node, vector<int>& vals) {
15        if(!node) return;
16        inorder(node->left, vals);
17        vals.push_back(node->val);
18        inorder(node->right, vals);
19    }
20    TreeNode* build(const vector<int>& vals, int l, int r) {
21        if(l > r) return nullptr;
22        int mid = (l + r) / 2;
23        TreeNode* node = new TreeNode(vals[mid]);
24        node->left  = build(vals, l, mid - 1);
25        node->right = build(vals, mid + 1, r);
26        return node;
27    }
28    TreeNode* balanceBST(TreeNode* root) {
29        vector<int> vals;
30        inorder(root, vals);
31        return build(vals, 0, (int)vals.size() - 1);
32    }
33};