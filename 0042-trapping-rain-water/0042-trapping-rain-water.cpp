class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = 0, rmax = 0;
        //using two pointers
        int l = 0, r = n-1;
        int total = 0;
        //until l and r meet
        while(l<r){
            //as we always move the smallest, we move either left or right
            //if left is smaller
            if(height[l] <= height[r]){
                //if element is smaller than lmax then add to total
                if(height[l] < lmax){
                    total += lmax - height[l];
                }
                //or else we update the lmax
                else{
                    lmax = height[l];
                }
                l++;
            }
            //if right element is smaller
            else{
                if(rmax > height[r]){
                    total += rmax - height[r];
                }
                else{
                    rmax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};