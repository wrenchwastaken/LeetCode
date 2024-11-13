class Solution {
public:
    long long totalTime(vector<int>& piles, int h){
        long long total = 0;
        for(int i=0;i<piles.size();i++){
            total += ceil((double)(piles[i]) / (double)(h));
        }
        return total;
    }
    int maxofArr(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = maxofArr(piles);
        while(l<=r){
            int m = l + (r-l)/2;
            long long total = totalTime(piles, m);
            if(total<=h){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};