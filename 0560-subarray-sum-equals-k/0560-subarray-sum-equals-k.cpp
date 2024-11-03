class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int n = nums.size();
       map<int,int> mpp;
       mpp[0] = 1;
       int prefixSum = 0, count = 0;
       for(int i = 0;i<n;i++){
            prefixSum += nums[i];
            int removal = prefixSum - k;
            count += mpp[removal];
            mpp[prefixSum]++;
        }
        return count; 
    }
};