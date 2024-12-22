class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return nearlyK(nums,k) - nearlyK(nums,k-1);
    }
    int nearlyK(vector<int> &nums, int k){
        int n = nums.size();
        int l = 0, r = 0;
        int count = 0;
        int sum = 0;
        //base case
        if(k<0){
            return 0;
        }
        while(r<n){
            sum += (nums[r]%2);
            //if out of limit
            while(sum > k){
                //decrease sum and shrink window
                sum -= (nums[l]%2);
                l++;
            }
            //if under the limit
            if(sum <= k){
                //update count
                count += r-l+1;
            }
            //expand window
            r++;
        }
        return count;
    }
};