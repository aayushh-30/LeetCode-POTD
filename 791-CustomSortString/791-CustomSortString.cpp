// Last updated: 7/2/2025, 8:13:15 PM
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string ans = "";

        // Add characters in the order specified by 'order'
        for (char c : order) {
            while (freq[c - 'a'] > 0) {
                ans += c;
                freq[c - 'a']--;
            }
        }

        // Add remaining characters not in 'order'
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                ans += (char)('a' + i);
                freq[i]--;
            }
        }

        return ans;
    }
};
