class Solution {
    bool canReach(vector<int> &dist,double hour, int speed){
        double timeTaken = 0.0;
        int n = dist.size();
        for(int i=0;i<n;i++){
            if(i == n-1){
                timeTaken += dist[i]/(1.0 * speed);
                break;
            }
            timeTaken += ceil(dist[i]/(1.0 * speed));
        }

        return timeTaken <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int start = 1;
        int totalDist = 0;
        int end = 1e7;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(canReach(dist,hour,mid)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }

        }

        return ans;
        
    }
};