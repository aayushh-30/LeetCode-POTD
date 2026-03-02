// Last updated: 3/2/2026, 7:56:52 PM
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
13public:
14    bool isCompleteTree(TreeNode* root) {
15        if(root == nullptr) return true;
16        bool Null = false;
17
18        queue<TreeNode*> q;
19        q.push(root);
20
21        while(!q.empty()){
22            auto temp = q.front();
23            q.pop();
24            if(temp == nullptr){
25                Null = true;
26            }else{
27                if(Null) return false;
28                q.push(temp->left);
29                q.push(temp -> right);
30            }
31        }
32
33        return true;
34        
35    }
36};