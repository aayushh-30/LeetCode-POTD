// Last updated: 5/10/2025, 10:10:20 AM
class Solution {
    int countZeroes(vector<int> &arr){
        int count = 0;
        for(auto it:arr){
            if(it == 0){
                count++;
            }
        }

        return count;
    }
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        long long zero1 = countZeroes(nums1);
        long long zero2 = countZeroes(nums2);

        long long sum1 = accumulate(nums1.begin(),nums1.end(),zero1);
        long long sum2 = accumulate(nums2.begin(),nums2.end(),zero2);

        

        if (!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
            return -1;
        }
        return max(sum1, sum2);
        
    }
};