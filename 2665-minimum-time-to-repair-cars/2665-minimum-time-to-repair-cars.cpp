class Solution {
public:
    bool canRepairInTime(vector<int>& ranks, int cars, long long mid) {
        long long totalCars = 0;  // Total cars that can be repaired within 'mid' time
        for (int rank : ranks) {
            totalCars += sqrt(mid / rank);  // Calculate cars this mechanic can repair
            if (totalCars >= cars) return true;  // Early exit if enough cars are assigned
        }
        return totalCars >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;  
        long long right = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars; // Max possible time
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;   // Found a valid time, try minimizing it
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};