// Last updated: 1/6/2026, 11:35:27 AM
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
14    int maxLevelSum(TreeNode* root) {
15        if (!root) return -1;  
16
17        queue<TreeNode*> q;
18        q.push(root);
19        //priority_queue<long long, vector<long long>, greater<long long>> pq; 
20        int lev = -1;
21        int l = 0;
22        long long currSum = INT_MIN;
23        while (!q.empty()) {
24            
25            long long sum = 0;
26            
27            int n = q.size();
28            l++;
29            for (int i = 0; i < n; i++) {
30                TreeNode* temp = q.front();
31                q.pop();
32                sum += temp->val;
33                if (temp->left) q.push(temp->left);
34                if (temp->right) q.push(temp->right);
35            }
36            if(sum>currSum){
37                lev = l;
38                currSum = sum;
39            }
40        }
41        return lev;
42    }
43};