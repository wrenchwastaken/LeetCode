class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m, 0);

        for (int i = 0; i < n; i++) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++) {
                // Handling the first cell
                if (i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                } else {
                    int up = INT_MAX;
                    int left = INT_MAX;
                    // Up direction sum if not in the first row
                    if (i > 0) {
                        up = grid[i][j] + prev[j];
                    }
                    // Left direction sum if not in the first column
                    if (j > 0) {
                        left = grid[i][j] + curr[j-1];
                    }
                    // The current cell value is the minimum of up and left
                    curr[j] = min(left, up);
                }
            }
            prev = curr;  // Update the previous row after the current row is done
        }
        return prev[m-1];  // Return the last element in prev which is the min path sum to the bottom-right corner
    }
};