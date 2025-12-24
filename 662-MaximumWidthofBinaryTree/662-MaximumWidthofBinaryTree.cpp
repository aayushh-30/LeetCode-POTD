// Last updated: 12/24/2025, 12:26:08 PM
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
14    int widthOfBinaryTree(TreeNode* root) {
15        if(!root) return 0;
16        queue<pair<TreeNode*,long long>> q;
17        long long ans = 0;
18        q.push({root,0});
19        while(!q.empty()){
20            int n = q.size();
21            long long min = q.front().second;
22            long long st,en;
23            for(int i=0;i<n;i++){
24                auto temp = q.front();
25                TreeNode* k = temp.first;
26                q.pop();
27                long long curr_ind = temp.second - min;
28                if(i==0) st = curr_ind;
29                if(i==n-1) en = curr_ind;
30                if(k->left) q.push({k->left,curr_ind*2+1});
31                if(k->right) q.push({k->right,curr_ind*2+2});
32            }
33            ans = max(ans,en-st+1);
34        }
35
36        return ans;
37        
38        
39    }
40};