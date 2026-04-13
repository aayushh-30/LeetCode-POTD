// Last updated: 4/13/2026, 12:39:24 PM
1class Solution {
2public:
3    string trafficSignal(int timer) {
4        if(timer == 0) return "Green";
5        else if(timer == 30) return "Orange";
6        else if(timer>30 && timer<=90) return "Red";
7        else return "Invalid";
8        
9    }
10};