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
    int count = 0;
    void fun(TreeNode* root,int Parent){
        if(root==nullptr) return;
        fun(root->left,max(Parent,root->val));
        if(root->val>=Parent){
            count++;
        }
        fun(root->right,max(Parent,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        fun(root,INT_MIN);
        return count;
        
    }
};