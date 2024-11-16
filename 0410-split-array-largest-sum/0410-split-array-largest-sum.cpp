class Solution {
public:
    int possible(vector<int>& nums, int split){
        int cases = 1, allotment = 0;
        for(int i=0;i<nums.size();i++){
            if(allotment + nums[i] <= split){
                allotment += nums[i];
            }
            else{
                cases += 1;
                allotment = nums[i];
            }
        }
        return cases;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(),nums.end(),0);
        while(l<=r){
            int mid = l + (r-l)/2;
            if(possible(nums,mid) <= k){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};