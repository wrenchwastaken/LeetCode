class Solution {
public:
    double myPow(double x, int n) {
        long long num = n;
        double ans = 1;
        if(num<0){
            num = num*(-1);
            x = 1/x;
        }
        while(num > 0){
            if(num%2 != 0){
                ans *= x;
                num -= 1;
            }
            
            x = x*x;
            num = num/2;
            
        }
        return ans;
    }
};