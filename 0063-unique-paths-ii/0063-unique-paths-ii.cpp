class Solution {
public:
    int func(int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // Base conditions
                if (matrix[i][j] == 1) {
                    /* If there's an obstacle at the 
                    cell, no paths can pass through it*/
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    /* If we are at the starting 
                    point, there is one path to it*/
                    dp[i][j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                /* Check if we can move up and left 
                (if not at the edge of the maze)*/
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                /* Total number of paths to reach (i, j)
                is the sum of paths from above and left*/
                dp[i][j] = up + left;
            }
        }

        /* The final result is stored in dp[m-1][n-1],
        which represents the destination*/
        return dp[m - 1][n - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();   
        int n = obstacleGrid[0].size(); 

        // Initialize DP table to memoize results
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Return the total number of paths
        return func(m, n, obstacleGrid, dp);
    }
};