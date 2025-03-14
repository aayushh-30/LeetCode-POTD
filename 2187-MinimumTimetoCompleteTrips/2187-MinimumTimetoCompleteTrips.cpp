#define ll long long
class Solution {
    bool canCover(vector<int> &time, int totalTrips, ll t) {
        ll Trips = 0;
        for (int it : time) {
            Trips += (t / it);
            if (Trips >= totalTrips) return true; 
        }
        return Trips >= totalTrips;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll s = 1;
        ll e = *min_element(time.begin(), time.end()) * (ll)totalTrips;
        ll ans = 0;
        
        while (s <= e) {
            ll mid = s + (e - s) / 2;
            if (canCover(time, totalTrips, mid)) {
                ans = mid;
                e = mid - 1; 
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
