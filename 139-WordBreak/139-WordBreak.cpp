class Solution {
    unordered_map<int, bool> dp; // Memoization table
    
    bool fun(int start, string &s, set<string> &st) {
        if (start == s.length()) return true;
        if (dp.count(start)) return dp[start];

        for (int len = 1; len <= s.length() - start; len++) {
            string currString = s.substr(start, len);
            if (st.find(currString) != st.end() && fun(start + len, s, st)) {
                return dp[start] = true;
            }
        }
        return dp[start] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        return fun(0, s, st);
    }
};
