class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), right = n-1;
        int left = 0, mid = 0;
        while(mid<=right){
            if(nums[mid]==0){
                swap(nums[left],nums[mid]);
                left++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[right]);
                right--;
            }
        }
    }
};