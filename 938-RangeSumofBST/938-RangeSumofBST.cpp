// Last updated: 2/6/2026, 5:20:38 AM
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
13    // O(n) n -> number of nodes in a tree
14    void fun(TreeNode* root,int low,int high,int &sum){
15        if(root==nullptr) return;
16        fun(root->left,low,high,sum);
17        if(root->val>=low && root->val<=high) sum += root->val;
18        fun(root->right,low,high,sum);
19    }
20
21    int findSum(TreeNode* root){
22        if(root == nullptr) return 0;
23        return root->val + findSum(root->left) + findSum(root->right);
24    }
25
26    int fun2(TreeNode* rt,int l,int h){
27        if(rt == nullptr) return 0;
28        int sum = 0;
29        if(rt->val>=l && rt->val<=h){
30            sum += rt->val;
31            sum += fun2(rt->right,l,h) + fun2(rt->left,l,h);
32        }else if(rt->val<l){
33            sum += fun2(rt->right,l,h);
34        }else{
35            sum += fun2(rt->left,l,h);
36        }
37
38        return sum;
39    }
40
41public:
42    int rangeSumBST(TreeNode* root, int low, int high) {
43        return fun2(root,low,high);
44        
45    }
46};