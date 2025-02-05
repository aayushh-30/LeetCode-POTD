class Solution {
    vector<int> NSL(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> NSR(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        #define MOD 1000000007
        vector<int> left = NSL(arr);
        vector<int> right = NSR(arr);
        long long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            int el = i - left[i];
            int er = right[i] - i;
            sum = (sum + (1LL * arr[i] * el % MOD * er % MOD)) % MOD;
        }
        return (int)sum;
    }
};
