// Last updated: 5/7/2025, 7:25:31 AM
class Solution {
    int n,m;
    int dks(vector<vector<int>>& moveTime){
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> time(n,vector<int>(m,INT_MAX));
        queue<vector<int>> q; //time,row,col;
        time[0][0] = moveTime[0][0];
        q.push({0,0,0});
        while(!q.empty()){
            auto temp = q.front();
            int t = temp[0];
            int r = temp[1];
            int c = temp[2];
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int newtime = moveTime[nr][nc]-t;
                    int extraTime = 1;
                    if(newtime>0){
                        extraTime+=(newtime);
                    }
                    if(time[nr][nc]>t+extraTime){
                        time[nr][nc] = t + extraTime;
                        q.push({time[nr][nc],nr,nc});
                    }

                }
            }
        }
        return time[n-1][m-1];

    }
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n = moveTime.size();
        m = moveTime[0].size();

        return dks(moveTime);

        
    }
};