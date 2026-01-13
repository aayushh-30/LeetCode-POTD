// Last updated: 1/13/2026, 7:26:14 PM
1class Solution {
2public:
3    double separateSquares(vector<vector<int>>& squares) {
4
5        double totalArea = 0;
6        double maxY = 0;
7
8       
9        for (auto& sq : squares) {
10            double y = sq[1];
11            double side = sq[2];
12
13            totalArea += side * side;
14            maxY = max(maxY, y + side);
15        }
16
17        
18        auto isEnough = [&](double mid) {
19            double areaBelow = 0;
20
21            for (auto& sq : squares) {
22                double y = sq[1];
23                double side = sq[2];
24
25                if (y < mid) {
26                    double height = min(side, mid - y);
27                    areaBelow += height * side;
28                }
29            }
30
31            return areaBelow >= totalArea / 2;
32        };
33
34        
35        double low = 0;
36        double high = maxY;
37        double eps = 1e-5;
38
39        while (high - low > eps) {
40            double mid = (low + high) / 2;
41
42            if (isEnough(mid))
43                high = mid;
44            else
45                low = mid;
46        }
47
48        return high;
49    }
50};
51