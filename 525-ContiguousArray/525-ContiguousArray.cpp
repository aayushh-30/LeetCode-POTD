class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        int cnt = 0;
        int size = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) cnt--;
            else cnt++;
            if(cnt == 0) size = i+1;
            arr[i] = cnt;
        }
        
        
        unordered_map<int,int> mp; //number, first_occurence
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                size = max(size,i - mp[arr[i]]);
            }else{
                mp[arr[i]] = i;
            }
        }

        return size;

        
    }
};