class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1,result = -1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m] == target){
                result = m;
                return result;
            }
            else if(nums[m]<target){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return result;
    }
};