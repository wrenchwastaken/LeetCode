class Solution {
public:

    int findPosition(vector<int>& nums, int target, bool findFirst) {
        int l = 0, r = nums.size()-1;
        int pos1 = -1;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m] == target){
                pos1 = m;
                if(findFirst){
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
            else if(nums[m]<target){
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return pos1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1,-1};
        result[0] = findPosition(nums,target,true);
        if(result[0]!= -1){
            result[1] = findPosition(nums,target,false);
        }
        return result;
    }
};