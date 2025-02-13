int minOperations(vector<int>& nums, int k) 
{
    int ctr =0;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int num: nums) minHeap.push(num);
    while(minHeap.top()<k)
    {
        int a = minHeap.top(); minHeap.pop();
        int b = minHeap.top(); minHeap.pop();
        if(a > (INT_MAX-b)/2) minHeap.push(k);
        else minHeap.push(2*a+b);
        ctr ++;
    }
    return ctr;
}