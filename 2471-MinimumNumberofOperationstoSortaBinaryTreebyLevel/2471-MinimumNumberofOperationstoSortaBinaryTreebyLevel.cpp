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
    int fun(vector<int> arr){
        map<int,int> mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]] = i;
        vector<int> cp = arr;
        sort(cp.begin(),cp.end());
        int cnt = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] != cp[i]){
                int ai = mp[cp[i]];
                swap(arr[i],arr[ai]);
                mp[arr[ai]] = ai;
                mp[arr[i]] = i;

                cnt++;
            }
        }
        return cnt;
        
    }
    int traversal(TreeNode* root){
        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> ele;
            while(n--){
                auto temp = q.front();
                q.pop();
                ele.push_back(temp-> val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            count += fun(ele);

        }
        return count;
    }
public:
    int minimumOperations(TreeNode* root) {
        if(root==nullptr) return 0;
        return traversal(root);

        
    }
};