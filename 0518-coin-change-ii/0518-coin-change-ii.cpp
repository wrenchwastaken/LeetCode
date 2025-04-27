class Solution {
public:
    int solve(int i, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(i == coins.size() && target != 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int notTake = 0 + solve(i+1,target,coins,dp);
        int take = 0;
        if(coins[i] <= target){
            take = solve(i,target-coins[i],coins, dp);
        }
        return dp[i][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(0,amount,coins,dp);
    }
};