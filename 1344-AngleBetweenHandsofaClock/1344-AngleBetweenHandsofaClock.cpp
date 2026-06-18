// Last updated: 6/18/2026, 10:44:25 AM
1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        double minuteAngle = 6.0 * minutes;
5        double hourAngle = 30.0 * (hour % 12) + 0.5 * minutes;
6
7        double diff = abs(hourAngle - minuteAngle);
8
9        return min(diff, 360.0 - diff);
10    }
11};