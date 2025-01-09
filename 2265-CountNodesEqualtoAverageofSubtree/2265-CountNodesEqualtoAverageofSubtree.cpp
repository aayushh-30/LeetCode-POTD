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
    int cnt = 0;
    pair<int,int> fun(TreeNode* root){
        //sum,nodes
        if(root==nullptr) return {0,0};

        auto left = fun(root->left);
        auto right = fun(root->right);

        if((root->val+left.first+right.first)/(1+left.second+right.second)==root->val){
            cnt++;
        }


        return {root->val+left.first+right.first,1+left.second+right.second};

    }
public:
    int averageOfSubtree(TreeNode* root) {
        auto k = fun(root);
        return cnt;
        
    }
};