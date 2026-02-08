// Last updated: 2/9/2026, 1:12:05 AM
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
13    int height(TreeNode* root){
14        if(root==nullptr) return 0;
15        return 1+max(height(root->left),height(root->right));
16    }
17
18    void placing(TreeNode* root,int r,int c,vector<vector<string>> &ans,int h){
19        if(root==nullptr) return;
20       
21        ans[r][c] = to_string(root->val);
22         if (r == h - 1) return;
23        int offset = 1 << (h - r - 2);
24        
25        placing(root->left,r+1,c-offset,ans,h);
26        
27        placing(root->right,r+1,c+offset,ans,h);
28
29    }
30public:
31    vector<vector<string>> printTree(TreeNode* root) {
32        int h = height(root);
33        int m = h;
34        int n = (1 << h) - 1;
35
36
37        vector<vector<string>> ans(m,vector<string>(n,""));
38
39        placing(root,0,(n-1)/2,ans,h);
40
41        return ans;
42
43
44        
45    }
46};