class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorTotal = nums.size();
        for(int i=0;i<nums.size();i++){
            xorTotal ^= i^nums[i];
        }
        return xorTotal;
    }
};