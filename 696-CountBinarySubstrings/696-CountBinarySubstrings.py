# Last updated: 2/19/2026, 10:09:46 PM
1class Solution(object):
2    def countBinarySubstrings(self, s):
3        groups = [1]
4        for i in range(1, len(s)):
5            if s[i-1] != s[i]:
6                groups.append(1)
7            else:
8                groups[-1] += 1
9
10        ans = 0
11        for i in range(1, len(groups)):
12            ans += min(groups[i-1], groups[i])
13        return ans