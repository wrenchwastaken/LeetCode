class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int elem;
        for(int i = 0;i<nums.size();i++){
            if(count == 0){
                count++;
                elem = nums[i];
            }
            else if(nums[i] == elem){
                count++;
            }
            else{
                count--;
            }
        }
        int countForMj = 0;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] == elem){
                count++;
            }
        }
        if(count > nums.size()/2){
            return elem;
        }
        return -1;
    }
};