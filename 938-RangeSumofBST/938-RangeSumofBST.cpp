// Last updated: 2/6/2026, 4:57:59 AM
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
13    void fun(TreeNode* root,int low,int high,int &sum){
14        if(root==nullptr) return;
15        fun(root->left,low,high,sum);
16        if(root->val>=low && root->val<=high) sum += root->val;
17        fun(root->right,low,high,sum);
18    }
19public:
20    int rangeSumBST(TreeNode* root, int low, int high) {
21        int sum = 0;
22        fun(root,low,high,sum);
23        return sum;
24        
25    }
26};