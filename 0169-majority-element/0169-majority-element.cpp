class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mpp;
        int n = nums.size();
        int comp = n/2;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            if(it.second > comp){
                return it.first;
            }
        }
        return -1;
    }
};