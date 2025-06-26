// Last updated: 6/26/2025, 11:04:02 PM
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        int m = name.length();
        int n = typed.length();
        if(m>n) return false;
        while(j<n){
            if(name[i] == typed[j]){
                i++;
                j++;
            }else{
                if(j>0 && typed[j] == typed[j-1]){
                    j++;
                }else{
                    return false;
                }
            }
        }

        return i == m;
        
    }
};