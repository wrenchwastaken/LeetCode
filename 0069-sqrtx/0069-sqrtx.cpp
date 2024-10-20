class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;  
        
        int l = 1, r = x;
        while (l <= r) {  
            int m = l + (r - l) / 2;
            int sqroot = x / m;  
            
            if (sqroot == m) {
                return m;  
            } 
            else if (sqroot < m) {
                r = m - 1;  
            } 
            else {
                l = m + 1;  
            }
        }
        return r;  
    }
};
