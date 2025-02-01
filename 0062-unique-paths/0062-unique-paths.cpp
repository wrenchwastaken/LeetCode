class Solution {
public:
    int solve(int m, int n){
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i ==0 && j == 0){
                    temp[j] = 1;
                    continue;
                }
                int u = 0;
                int l = 0;
                if(i>0){
                    u = prev[j];
                }
                if(j>0){
                    l = temp[j-1];
                }
                temp[j] = u + l;
            }
            prev = temp;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        return solve(m,n);
    }
};