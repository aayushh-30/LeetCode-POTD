// Last updated: 8/10/2025, 1:55:36 PM
class Solution {
    vector<int> digitFreq(int n){
        vector<int> freq(10,0);
        while(n>0){
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }
        return freq;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> fr = digitFreq(n);

        for(int i=0;i<=30;i++){
            vector<int> q = digitFreq((int)(pow(2,i)));
            if(q == fr) return true;

        }

        return false;
        
    }
};