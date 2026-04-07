// Last updated: 4/7/2026, 7:13:28 AM
1class Robot {
2private:
3    bool moved = false;
4    int idx = 0;
5    vector<pair<int, int>> pos;
6    vector<int> dir;
7    unordered_map<int, string> to_dir = {
8        {0, "East"}, {1, "North"}, {2, "West"}, {3, "South"}};
9
10public:
11    Robot(int width, int height) {
12        for (int i = 0; i < width; ++i) {
13            pos.emplace_back(i, 0);
14            dir.emplace_back(0);
15        }
16        for (int i = 1; i < height; ++i) {
17            pos.emplace_back(width - 1, i);
18            dir.emplace_back(1);
19        }
20        for (int i = width - 2; i >= 0; --i) {
21            pos.emplace_back(i, height - 1);
22            dir.emplace_back(2);
23        }
24        for (int i = height - 2; i > 0; --i) {
25            pos.emplace_back(0, i);
26            dir.emplace_back(3);
27        }
28        dir[0] = 3;
29    }
30
31    void step(int num) {
32        moved = true;
33        idx = (idx + num) % pos.size();
34    }
35
36    vector<int> getPos() { return {pos[idx].first, pos[idx].second}; }
37
38    string getDir() {
39        if (!moved) {
40            return "East";
41        }
42        return to_dir[dir[idx]];
43    }
44};