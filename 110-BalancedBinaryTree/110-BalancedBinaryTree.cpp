// Last updated: 2/8/2026, 2:11:22 PM
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
13    int fun(TreeNode* root,bool &ans){
14        if(root==nullptr) return 0;
15        int lh = fun(root->left,ans);
16        int rh = fun(root->right,ans);
17        if(abs(lh-rh)>=2){
18            ans = false;
19        }
20        return 1+max(lh,rh);
21    }
22
23public:
24    bool isBalanced(TreeNode* root) {
25        
26        bool ans = true;
27        fun(root,ans);
28        return ans;
29
30        
31        
32    }
33};