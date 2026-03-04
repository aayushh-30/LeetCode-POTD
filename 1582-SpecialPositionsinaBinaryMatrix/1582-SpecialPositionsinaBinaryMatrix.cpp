// Last updated: 3/4/2026, 9:51:35 AM
1class Solution {
2    bool fun(vector<vector<int>>& mat,int i,int j){
3
4        for(int k = 0;k<mat.size();k++){
5           if(k!=i && mat[k][j]==1){
6               return false;
7           }
8
9        }
10        for(int k = 0;k<mat[i].size();k++){
11            if(k!=j && mat[i][k]==1){
12               return false;
13           }
14
15
16        }
17
18        return true;
19
20    }
21public:
22    int numSpecial(vector<vector<int>>& mat) {
23        int count = 0;
24        for(int i=0;i<mat.size();i++){
25            for(int j = 0;j<mat[i].size();j++){
26                if(mat[i][j]==1 && fun(mat,i,j)){
27                    count++;
28                }
29            }
30        }
31        return count;
32        
33    }
34};