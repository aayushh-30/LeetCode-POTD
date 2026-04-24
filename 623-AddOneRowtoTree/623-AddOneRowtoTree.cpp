// Last updated: 4/24/2026, 1:11:43 PM
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
13    TreeNode* fun(TreeNode* root,int curr,int depth,int val){
14        if(root==nullptr) return nullptr;
15        if(curr == depth - 1){
16            TreeNode* lt = root->left;
17            TreeNode* rt = root -> right;
18
19            TreeNode* lc = new TreeNode(val);
20            TreeNode* rc = new TreeNode(val);
21            root->left = lc;
22            root->left ->left = lt;
23            root->right = rc;
24            root->right -> right = rt;
25            return root;
26        }
27        root->left = fun(root->left,curr+1,depth,val);
28        root->right = fun(root->right,curr+1,depth,val);
29
30        return root;
31
32
33    }
34public:
35    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
36        if(depth == 1){
37            TreeNode* newRoot = new TreeNode(val);
38            newRoot->left = root;
39            return newRoot;
40        }
41        return fun(root,1,depth,val);
42        
43    }
44};