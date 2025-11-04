// Last updated: 11/4/2025, 10:37:17 AM
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto it:nums){
            pq.push(abs(it));
        }

        long long ans = pq.top();
        pq.pop();
        ans *= pq.top();
        pq.pop();

        ans *= 100000;

        return ans;
        
    }
};