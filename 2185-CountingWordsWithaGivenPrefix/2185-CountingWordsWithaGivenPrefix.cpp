class Solution {
    bool isPref(string word,string pref){
        int i = 0;
        while(word[i]==pref[i]){
            i++;
            if(i==pref.length()) return true;
        }
        return false;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto it:words){
            if(isPref(it,pref)){
                count++;
            }
        }
        return count;
        
    }
};