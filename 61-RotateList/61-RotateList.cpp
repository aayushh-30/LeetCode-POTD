// Last updated: 5/5/2026, 8:47:06 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12    int len(ListNode* k){
13        if(k==nullptr) return 0;
14        return 1+len(k->next);
15    }
16public:
17    ListNode* rotateRight(ListNode* head, int k) {
18        
19        if(head==nullptr) return head;
20        if(head->next==nullptr) return head;
21        int lengt = len(head);
22        k = (k>lengt)?k%lengt:k;
23        for(int i=0;i<k;i++){
24            ListNode* front = head;
25            ListNode* back = nullptr;
26            while(front->next){
27                
28                back = front;
29                front = front->next;
30                
31            }
32            front->next = head;
33            head = front;
34            back->next = nullptr;
35            
36        }
37        return head;
38        
39    }
40};