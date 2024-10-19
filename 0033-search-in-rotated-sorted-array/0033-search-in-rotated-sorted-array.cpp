class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int result = -1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m] == target){
                result = m;
                return result;
            }
            if(nums[l]<=nums[m]){
                if(nums[l]<= target && target < nums[m]){
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
            else{
                if(nums[m] < target && target <= nums[r]){
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
        }
        return result;
    }
};