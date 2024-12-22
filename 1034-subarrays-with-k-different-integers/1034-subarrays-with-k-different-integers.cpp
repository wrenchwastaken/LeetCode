class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return nearlyK(nums,k) - nearlyK(nums,k-1);
    }
    int nearlyK(vector<int>& nums, int k){
        int l = 0, r = 0;
        int count = 0;
        //map to keep track of frequency
        unordered_map<int,int> mpp;
        int n = nums.size();
        while(r<n){
            //add to save frequency on map
            mpp[nums[r]]++;
            //if size is over limit
            while(mpp.size() > k){
                //reduce frequency
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    //if frequency is 0, remove the element
                    mpp.erase(nums[l]);
                }
                //shrink the window
                l++;
            }
            //if under the limit
            if(mpp.size() <= k){
                //include all combos in count
                count += r-l+1;
            }
            //expand the window
            r++;
        }
        return count;
    }
};