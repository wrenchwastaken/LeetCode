class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m, 0);

        // Initialize the first element of the DP table
        dp[0] = grid[0][0];

        // Initialize the first row
        for (int j = 1; j < m; ++j) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        // Process all other rows
        for (int i = 1; i < n; ++i) {
            // Update the first column for this row
            dp[0] += grid[i][0];
            for (int j = 1; j < m; ++j) {
                // Update dp[j] considering the minimum from top or left
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }

        // The last element in dp array contains the answer
        return dp[m - 1];
    }
};