// Last updated: 4/1/2026, 11:09:31 AM
1class Solution {
2public:
3    std::vector<int> survivedRobotsHealths(std::vector<int>& positions, std::vector<int>& healths, std::string directions) {
4        int n = positions.size();
5        std::vector<int> result(n, -1); // -1 indicates a robot is destroyed
6
7        // Combine positions, healths, and directions into a single array for sorting
8        std::vector<std::tuple<int, int, char, int>> robots;
9        for (int i = 0; i < n; ++i) {
10            robots.emplace_back(positions[i], healths[i], directions[i], i);
11        }
12
13        // Sort robots by their positions
14        std::sort(robots.begin(), robots.end());
15
16        std::stack<std::tuple<int, int, char, int>> st; // stack to handle collisions (position, health, direction, index)
17        
18        for (const auto& robot : robots) {
19            int pos = std::get<0>(robot);
20            int health = std::get<1>(robot);
21            char dir = std::get<2>(robot);
22            int index = std::get<3>(robot);
23            
24            if (dir == 'R') {
25                st.push(robot);
26            } else { // dir == 'L'
27                while (!st.empty() && std::get<2>(st.top()) == 'R') {
28                    auto rightRobot = st.top();
29                    int rightHealth = std::get<1>(rightRobot);
30                    int rightIndex = std::get<3>(rightRobot);
31
32                    if (rightHealth > health) {
33                        std::get<1>(st.top()) -= 1;
34                        health = -1; // this left robot is destroyed
35                        break;
36                    } else if (rightHealth < health) {
37                        health -= 1;
38                        st.pop();
39                    } else {
40                        st.pop();
41                        health = -1; // both are destroyed
42                        break;
43                    }
44                }
45                if (health > 0) {
46                    st.push(std::make_tuple(pos, health, dir, index));
47                }
48            }
49        }
50
51        // Collect survivors from the stack
52        std::vector<int> survivors;
53        while (!st.empty()) {
54            auto robot = st.top();
55            st.pop();
56            int index = std::get<3>(robot);
57            result[index] = std::get<1>(robot); // store the remaining health
58        }
59
60        // Remove destroyed robots (those with -1 health) and return result
61        std::vector<int> final_result;
62        for (int health : result) {
63            if (health != -1) {
64                final_result.push_back(health);
65            }
66        }
67        return final_result;
68    }
69};
70