class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0;
        int maxSum = 0;
        int n = cardPoints.size();
        int l = 0, r = n-1;
        for(int i=l;i<k;i++){
            lsum += cardPoints[i];
            maxSum = max(lsum,maxSum);
        }
        for(int i=k-1;i>=0;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[r];
            r--;
            maxSum = max(maxSum, lsum+rsum);
        }
        return maxSum;
    }
};