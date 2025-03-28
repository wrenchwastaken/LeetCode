class Solution {
public:
    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n); // ✅ Fix: Allocate space
        stack<int> st;
        
        for(int i = n-1; i >=0 ; i--) {
            int curr = arr[i];
            // Maintain monotonic stack
            while(!st.empty() && curr < arr[st.top()]) {
                st.pop();
            }
            // Assign index or default value `n`
            ans[i] = (!st.empty()) ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n); // ✅ Fix: Allocate space
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            int curr = arr[i];
            // Maintain monotonic increasing stack
            while(!st.empty() && arr[st.top()] >= curr) { // ✅ Fix: Use `>=`
                st.pop();
            }
            ans[i] = (!st.empty()) ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long sum = 0;

        // Compute Next Smaller Element (NSE) and Previous Smaller Element (PSE)
        vector<int> NSE = nse(arr);
        vector<int> PSE = pse(arr);

        for(int i = 0; i < n; i++) {
            // ✅ Fix: Correct `l` and `r` calculations
            int l = i - PSE[i]; // Left distance
            int r = NSE[i] - i; // Right distance

            // Contribution formula
            long long freq = (l * r) % mod;
            long long val = (freq * arr[i]) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};
