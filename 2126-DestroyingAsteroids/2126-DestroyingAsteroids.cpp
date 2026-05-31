// Last updated: 6/1/2026, 4:33:24 AM
1class Solution {
2public:
3    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
4        long long planet = mass;
5        sort(asteroids.begin(),asteroids.end());
6        for(int i=0;i<asteroids.size();i++){
7            if(planet<asteroids[i]){
8                return false;
9            }
10            planet+=asteroids[i];
11        }
12        return true;
13        
14    }
15};