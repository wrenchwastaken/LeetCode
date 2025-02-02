class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0), curr(m,0);
        //base case
        for(int j=0;j<m;j++){
            prev[j] = matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j] + prev[j];
                int l = matrix[i][j];
                int r = matrix[i][j];
                if(j-1>=0){
                    l += prev[j-1];
                }
                else{
                    l += 1e8;
                }
                if(j+1<m){
                    r += prev[j+1];
                }
                else{
                    r += 1e8;
                }
                curr[j] = min(up, min(l,r));
            }
            prev = curr;
        }
        int maxi = 1e8;
        for(int j=0;j<m;j++){
            maxi = min(maxi, prev[j]);
        }
        return maxi;
    }
};