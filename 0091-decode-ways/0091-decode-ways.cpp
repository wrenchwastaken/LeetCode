class Solution {
public:
    int decodeWays(int i, string &s, vector<int> &dp){
        //if we reached end of string
        if(i == s.size()){
            return 1;
        }
        //if the current character is 0 
        if(s[i] == '0'){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        //start with taking with 1 index
        int ways = decodeWays(i+1,s,dp);
        //if there are more letters
        if(i+1 < s.size()){
            //take the second digit
            int twoD = (s[i] - '0')*10 + (s[i+1] - '0');
            //if it lies between 10 and 26
            if(twoD >= 10 && twoD <= 26){
                //add another way
                ways += decodeWays(i+2,s,dp);
            }
        }
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return decodeWays(0,s,dp);
    }
};