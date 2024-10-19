class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), count = 0;
        int m = rows - 1, n = 0;
        while(m>=0 && n<cols){
            if(grid[m][n]>=0){
                n++;
            }
            else{
                count += cols-n;
                m--;
            }
        }
        return count;
    }
};