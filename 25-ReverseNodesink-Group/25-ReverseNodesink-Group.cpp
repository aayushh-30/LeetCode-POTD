// Last updated: 1/24/2026, 10:32:50 AM
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
12    void rev(ListNode* &currHead, ListNode* &nextHead, ListNode* &prevTail) {
13        ListNode* prev = nextHead;
14        ListNode* curr = currHead;
15        ListNode* tail = currHead;   
16
17        while (curr != nextHead) {
18            ListNode* temp = curr->next;
19            curr->next = prev;
20            prev = curr;
21            curr = temp;
22        }
23
24        prevTail->next = prev;   // connect previous group
25        prevTail = tail;         // update prevTail
26        currHead = nextHead;     // move currHead forward
27    }
28
29public:
30    ListNode* reverseKGroup(ListNode* head, int k) {
31        if (!head || k == 1) return head;
32
33        ListNode dummy(-1);
34        dummy.next = head;
35
36        ListNode* prevTail = &dummy;
37        ListNode* currHead = head;
38
39        int currLen = 0;
40        ListNode* temp = head;
41
42        while (temp) {
43            currLen++;
44            if (currLen == k) {
45                ListNode* nextHead = temp->next;
46                rev(currHead, nextHead, prevTail);
47                temp = currHead;
48                currLen = 0;
49            } else {
50                temp = temp->next;
51            }
52        }
53
54        return dummy.next;
55    }
56};
57