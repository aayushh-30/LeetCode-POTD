// Last updated: 5/5/2026, 8:48:10 PM
1class Solution {
2public:
3    int countVowels(const string& w) {
4        int cnt = 0;
5        for (char c : w)
6            if (string("aeiou").find(c) != string::npos)
7                cnt++;
8        return cnt;
9    }
10
11    string reverseWords(string s) {
12        stringstream ss(s);
13        vector<string> words;
14        string word;
15
16        while (ss >> word)
17            words.push_back(word);
18
19        int target = countVowels(words[0]);
20
21        for (int i = 1; i < words.size(); i++) {
22            if (countVowels(words[i]) == target)
23                reverse(words[i].begin(), words[i].end());
24        }
25
26        string ans;
27        for (int i = 0; i < words.size(); i++) {
28            if (i)
29                ans += " ";
30            ans += words[i];
31        }
32        return ans;
33    }
34};
35