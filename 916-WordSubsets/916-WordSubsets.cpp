class Solution {
    vector<int> makeFreq(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        return freq;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Create the maximum frequency vector for words2
        vector<int> maxFreq(26, 0);
        for (string& word : words2) {
            vector<int> freq = makeFreq(word);
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        // Check each word in words1
        vector<string> result;
        for (string& word : words1) {
            vector<int> freq = makeFreq(word);
            bool isSubset = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset) {
                result.push_back(word);
            }
        }

        return result;
    }
};
