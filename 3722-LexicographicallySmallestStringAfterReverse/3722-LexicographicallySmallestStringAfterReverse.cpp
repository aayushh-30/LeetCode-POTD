// Last updated: 10/25/2025, 10:28:27 PM
class Solution {
public:
    string lexSmallest(string s) {
        int n = s.length();
        string cp = s;
        reverse(cp.begin(), cp.end());
        string ans = cp;

        for (int i = 1; i < n; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            reverse(left.begin(), left.end());
            ans = min(ans, left + right);
            reverse(left.begin(), left.end());

            reverse(right.begin(), right.end());
            ans = min(ans, left + right);
            reverse(right.begin(), right.end());
        }

        return ans;
        
    }
};