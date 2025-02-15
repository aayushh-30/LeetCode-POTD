class Solution {
public:
    vector<vector<string>> ans;
    vector<string> arr;

    bool isPalindrome(string q) {
    string cp = q;
    reverse(cp.begin(), cp.end());
    return q == cp;
    }

    void fun(int i, int j, string s) {
        if (i == j) { 
            ans.push_back(arr);
            return;
        }
        
        for (int len = 1; len <= j - i; len++) {
            string temp = s.substr(i, len);
            if (isPalindrome(temp)) {
                arr.push_back(temp);
                fun(i + len, j, s);  
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        fun(0,s.length(),s);
        return ans;
        
    }
};