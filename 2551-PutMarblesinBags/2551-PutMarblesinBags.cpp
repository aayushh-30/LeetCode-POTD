// Last updated: 3/31/2025, 8:52:29 AM
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> pairSum;
        int n = weights.size();
        for(int i=0;i<n-1;i++){
            pairSum.push_back(weights[i]+weights[i+1]);
        }
        sort(pairSum.begin(),pairSum.end());
        long long minSum = 0;
        long long maxSum = 0;
        for(int i=0;i<k-1;i++){
            minSum += pairSum[i];
            maxSum += pairSum[n-i-2];
        }

        return maxSum - minSum;
        
    }
};