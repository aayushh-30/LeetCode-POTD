/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    stack<ListNode*> st;
    vector<int> ans;
    void fun(ListNode* head){
        if(head->next == nullptr){
            st.push(head);
            return;
        }
        fun(head->next);
        while(!st.empty() && head->val >= st.top()->val){
            st.pop();
        }

        if(st.empty() == false && head->val<st.top()->val){
            ans.push_back(st.top()->val);
            st.push(head);
        }
        if(st.empty()){
            ans.push_back(0);
            st.push(head);
        }
        
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        
        fun(head);
        reverse(ans.begin(),ans.end());
        ans.push_back(0);
        return ans;
       
    }
};