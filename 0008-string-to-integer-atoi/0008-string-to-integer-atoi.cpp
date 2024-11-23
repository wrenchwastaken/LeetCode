class Solution {
public:
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    } 
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long result = 0;  // Using long to handle overflow before clamping
        int sign = 1;

        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Determine the sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        while (i < n && isDigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // Step 4: Clamp the result to the 32-bit signed integer range
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;

            i++;
        }

        // Return the final result
        return static_cast<int>(result * sign);
    }
};