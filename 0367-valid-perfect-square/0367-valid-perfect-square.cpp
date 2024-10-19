class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        bool ans = false;
        while(l<=r){
            int m = l + (r-l)/2;
            long long squared = (long long)m*m;
            if(squared == num){
                ans = true;
                return ans;
            }
            else if(squared < num){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return ans;
    }
};