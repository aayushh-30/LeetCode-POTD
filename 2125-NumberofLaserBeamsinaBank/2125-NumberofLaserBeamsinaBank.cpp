// Last updated: 10/27/2025, 12:18:38 PM
class Solution {
    int countOnes(const string& st) {
        int count = 0;
        for (char c : st)
            if (c == '1') count++;
        return count;
    }
public:
    int numberOfBeams(vector<string>& bank) {
        int last = 0;  
        int ans = 0;

        for (const string& row : bank) {
            int curr = countOnes(row);
            if (curr > 0) {
                ans += last * curr;
                last = curr; 
            }
        }
        return ans;
    }
};
