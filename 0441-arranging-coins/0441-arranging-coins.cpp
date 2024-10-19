class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0, r = n;
        while(l<=r){
            int m = l + (r-l)/2;
            long long stairs = (long long)m * (m + 1) / 2;
            if(stairs == n){
                return m;
            }
            else if(stairs < n){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return r;
    }
};