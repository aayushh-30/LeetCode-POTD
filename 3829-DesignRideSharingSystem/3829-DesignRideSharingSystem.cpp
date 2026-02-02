// Last updated: 2/2/2026, 12:07:12 PM
1class RideSharingSystem {
2public:
3    queue<int> rider,driver;
4    set<int> inDrive,cancelledRide;
5    RideSharingSystem() {
6        
7    }
8    
9    void addRider(int riderId) {
10        if(cancelledRide.find(riderId)!=cancelledRide.end()){
11            cancelledRide.erase(riderId);
12        }
13        rider.push(riderId);
14        
15    }
16    
17    void addDriver(int driverId) {
18        driver.push(driverId);
19    }
20    
21    vector<int> matchDriverWithRider() {
22        while(!rider.empty() && cancelledRide.find(rider.front())!=cancelledRide.end()){
23            rider.pop();
24        }
25        if(!driver.empty() && !rider.empty()){
26            int d1 = driver.front();
27            int r1 = rider.front();
28            driver.pop();
29            rider.pop();
30            inDrive.insert(r1);
31            return {d1,r1};
32        }
33        return {-1,-1};
34        
35    }
36    
37    void cancelRider(int riderId) {
38        if(inDrive.find(riderId)!=inDrive.end()) return;
39        cancelledRide.insert(riderId);
40        
41    }
42};
43
44/**
45 * Your RideSharingSystem object will be instantiated and called as such:
46 * RideSharingSystem* obj = new RideSharingSystem();
47 * obj->addRider(riderId);
48 * obj->addDriver(driverId);
49 * vector<int> param_3 = obj->matchDriverWithRider();
50 * obj->cancelRider(riderId);
51 */