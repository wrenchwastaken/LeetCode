class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        
        string previous = countAndSay(n - 1);
        string result = "";
        int count = 1;
        char digit = previous[0];
        
        for (int i = 1; i < previous.size(); i++) {
            if (previous[i] == digit) {
                count++;
            } else {
                result += to_string(count) + digit;
                count = 1;
                digit = previous[i];
            }
        }
        
        result += to_string(count) + digit;
        return result;
    }
};
