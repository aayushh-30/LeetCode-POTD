// Last updated: 2/7/2026, 11:13:49 PM
1class Solution {
2public:
3    int minimumDeletions(string s) {
4        int n = s.length();
5        stack<char> charStack;
6        int deleteCount = 0;
7
8        
9        for (int i = 0; i < n; i++) {
10            
11            if (!charStack.empty() && charStack.top() == 'b' && s[i] == 'a') {
12                charStack.pop();  
13                deleteCount++;  
14            } else {
15                charStack.push(s[i]);
16            }
17        }
18
19        return deleteCount;
20    }
21};