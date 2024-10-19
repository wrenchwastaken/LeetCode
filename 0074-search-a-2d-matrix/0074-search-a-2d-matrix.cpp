class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool result = false;
        int l = 0, r = rows*cols-1;
        while(l<=r){
            int m = l + (r-l)/2;
            int midVal = matrix[m/cols][m%cols];
            if(midVal == target){
                result = true;
                return result;
            }
            else if(midVal < target){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return result;
    }
};