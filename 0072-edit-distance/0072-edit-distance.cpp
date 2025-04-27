class Solution {
public:
    int solve(int i, int j, string &word1, string &word2,vector<vector<int>> &dp){
        //if word1 expires then delete all from word2
        if(i == word1.size()){
            return word2.size() - j;
        }
        //if word2 expires delete all from word1
        if(j == word2.size()){
            return word1.size() - i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //if both match then replace
        if(word1[i] == word2[j]){
            return dp[i][j] = solve(i+1,j+1,word1,word2,dp);
        }
        //otherwise find min of all 3 ops
        //i+1,j = delete, Insert(i, j+1), replace i+1,j+1
        else{
            return dp[i][j] = 1 + min({solve(i+1,j,word1,word2,dp), solve(i,j+1,word1,word2,dp), solve(i+1,j+1,word1,word2,dp)});

        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,word1,word2,dp);
    }
};