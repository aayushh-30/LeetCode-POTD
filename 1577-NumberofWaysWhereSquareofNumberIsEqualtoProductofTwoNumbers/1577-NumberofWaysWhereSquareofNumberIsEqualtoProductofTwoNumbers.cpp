// Last updated: 12/18/2025, 10:49:23 AM
1class Solution {
2    int countOfTrip(vector<int>& ar1,vector<int> &ar2){
3        unordered_map<long long,int> mp;
4        for(int i=0;i<ar1.size();i++){
5            mp[(long long)ar1[i]*(long long)ar1[i]]++;
6        }
7        int count = 0;
8        for(int i=0;i<ar2.size();i++){
9            for(int j=i+1;j<ar2.size();j++){
10                if(mp.find((long long)ar2[i]*ar2[j])!= mp.end()){
11                    count += mp[(long long)ar2[i]*ar2[j]];
12                }
13            }
14        }
15        return count;
16    }
17public:
18    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
19        int ans = 0;
20        ans += countOfTrip(nums1,nums2);
21        ans += countOfTrip(nums2,nums1);
22        return ans;
23    }
24};