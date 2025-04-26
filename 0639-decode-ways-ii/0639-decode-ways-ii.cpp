class Solution {
public:
    int M = 1000000007;
    
    int numDecodings(string s) {
        vector<long long> memo(s.length(), -1);
        return (int) ways(s, s.length() - 1, memo);
    }
    
    long long ways(string& s, int i, vector<long long>& memo) {
        if (i < 0) 
            return 1;
        if (memo[i] != -1) 
            return memo[i];
        
        if (s[i] == '*') {
            long long res = (9 * ways(s, i - 1, memo)) % M;
            
            if (i > 0 && s[i - 1] == '1')
                res = (res + 9 * ways(s, i - 2, memo)) % M;
            else if (i > 0 && s[i - 1] == '2')
                res = (res + 6 * ways(s, i - 2, memo)) % M;
            else if (i > 0 && s[i - 1] == '*')
                res = (res + 15 * ways(s, i - 2, memo)) % M;
            
            memo[i] = res;
            return res;
        }
        
        long long res = (s[i] != '0') ? ways(s, i - 1, memo) : 0;
        
        if (i > 0 && s[i - 1] == '1')
            res = (res + ways(s, i - 2, memo)) % M;
        else if (i > 0 && s[i - 1] == '2' && s[i] <= '6')
            res = (res + ways(s, i - 2, memo)) % M;
        else if (i > 0 && s[i - 1] == '*')
            res = (res + ((s[i] <= '6') ? 2 : 1) * ways(s, i - 2, memo)) % M;
        
        memo[i] = res;
        return res;
    }
};
