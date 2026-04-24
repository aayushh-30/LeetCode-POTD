// Last updated: 4/24/2026, 12:52:52 PM
1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int x=0,y=0;
5        for(int i=0;i<moves.length();i++){
6            if(moves[i]=='L' || moves[i]=='_'){
7                x--;
8            }
9            else{
10                x++;
11            }
12
13        }
14        for(int i=0;i<moves.length();i++){
15            if(moves[i]=='R' || moves[i]=='_'){
16                y++;
17            }
18            else{
19                y--;
20            }
21
22        }
23
24        if(abs(x)>abs(y))return abs(x);return abs(y);
25        
26    }
27};