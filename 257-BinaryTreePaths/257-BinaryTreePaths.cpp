// Last updated: 12/23/2025, 12:29:21 PM
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
13    vector<string> ans;
14    void fun(TreeNode* root,string path){
15        if(root==nullptr) return;
16        if(root->left==nullptr && root->right == nullptr) {
17            path += to_string(root->val);
18            ans.push_back(path);
19            path.pop_back();
20            return;
21        };
22        fun(root->left,path+to_string(root->val)+"->");
23        fun(root->right,path+to_string(root->val)+"->");
24    }
25public:
26    vector<string> binaryTreePaths(TreeNode* root) {
27        string path = "";
28        fun(root,path);
29        return ans;
30        
31    }
32};