class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1, count = 0;
        for(int k = n; k>=2; --k){
            int i = 0, j = k - 1;
            while(i<j){
                if(nums[i] + nums[j] > nums[k]){
                    count += j-i;
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return count;
    }
};