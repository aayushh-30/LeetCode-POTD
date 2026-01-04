// Last updated: 1/4/2026, 12:43:26 PM
1class Solution {
2    int countOfDivisor(int n){
3        int count = 0;
4        int sum = 0;
5        int i;
6        for(i=1;i*i<n;i++){
7            if(n % i == 0){
8                count+=2;
9                sum += (i)+(n/i);
10            }
11
12        }
13        if(i*i == n){
14            count++;
15            sum += i;
16        }
17        return count==4?sum:0;
18    }
19public:
20    int sumFourDivisors(vector<int>& nums) {
21        int sum = 0;
22        for(int i=0;i<nums.size();i++){
23           
24            sum += countOfDivisor(nums[i]);
25        }
26        return sum;
27        
28    }
29};