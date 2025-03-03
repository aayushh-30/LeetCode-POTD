/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void fun(TreeNode* root,int &total){
        if(root==nullptr) return;
        fun(root->right,total);
        total += root->val;
        root->val = total;
        fun(root->left,total);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int total = 0;
        fun(root,total);
        return root;
        
    }
};