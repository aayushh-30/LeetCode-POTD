class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);

        for(char ch:s){
            freq[ch-'a']++;
        }

        unordered_set<int> st;
        int count = 0;
        for(int i=0;i<26;i++){
            while(freq[i] > 0 && st.find(freq[i])!=st.end()){
                freq[i]--;
                count++;
            }
            st.insert(freq[i]);
        }

        return count;
        
    }
};