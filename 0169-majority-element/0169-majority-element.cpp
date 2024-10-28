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
        int countforMj = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == elem){
                countforMj++;
            }
        }
        if(countforMj > nums.size()/2){
            return elem;
        }
        return -1;
    }
};