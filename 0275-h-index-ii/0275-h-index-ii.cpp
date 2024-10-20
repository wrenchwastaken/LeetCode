class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0, r = citations.size()-1;
        int n = citations.size(), hIdx = 0;
        while(l<=r){
            int m = l + (r-l)/2;
            if(citations[m]>=n-m){
                hIdx = n-m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return hIdx;
    }
};