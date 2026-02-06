// Last updated: 2/7/2026, 1:13:56 AM
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
13    void fun(TreeNode* root,TreeNode* &currR){
14        if(root==nullptr) return;
15        fun(root->left,currR);
16        TreeNode* rt = new TreeNode(root->val);
17        currR -> right = rt;
18        currR = currR -> right;
19        fun(root->right,currR);
20    }
21public:
22    TreeNode* increasingBST(TreeNode* root) {
23        TreeNode* dummy = new TreeNode(-1);
24        TreeNode* curr = dummy;
25
26        fun(root, curr);
27        return dummy->right;
28
29        
30    }
31};