class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        int count1 = 0, count2 = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(count1 == 0 && el2 != nums[i]){
                count1 = 1;
                el1 = nums[i];
            }
            else if(count2 == 0 && el1 != nums[i]){
                count2 = 1;
                el2 = nums[i];
            }
            else if(nums[i] == el1){
                count1++;
            }
            else if(nums[i] == el2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int least = int(n/3);
        vector<int> result;
        count1 = 0;
        count2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == el1){
                count1++;
            }
            if(nums[i] == el2){
                count2++;
            }
        }
        if(count1>least){
            result.push_back(el1);
        }
        if(count2>least && el2 != el1){
            result.push_back(el2);
        }
        return result;
    }
};