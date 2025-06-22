// Last updated: 6/22/2025, 9:00:06 AM
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string> ans;
        if(n % k != 0){
            int times = k - (n%k);
            for(int i=0;i<times;i++){
                s.push_back(fill);
            }
        }
        n = s.length();
        for(int i=0;i<n;i+=k){
            ans.push_back(s.substr(i,k));
        }

        return ans;
        
    }
};