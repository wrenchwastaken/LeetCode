// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while(l<=r){
            int m = l + (r-l)/2;
            bool bad = isBadVersion(m);
            if(bad){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};