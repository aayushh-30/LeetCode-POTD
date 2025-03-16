class Solution {
    bool fun(vector<int>& ranks, int cars, long long time) {
        long long cnt = 0;
        for (int i = 0; i < ranks.size(); i++) {
            long long maxCars = sqrt((long double)time / ranks[i]);
            cnt += maxCars;
            if (cnt >= cars) return true;  // Early exit if enough cars are repaired
        }
        return cnt >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long h = (long long)*min_element(ranks.begin(), ranks.end()) * cars * 1LL * cars;
        long long ans = 0;
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (fun(ranks, cars, mid)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
