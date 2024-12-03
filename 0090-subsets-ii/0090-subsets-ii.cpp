class Solution {
public:
    void getAll(int idx, int n, vector<int> &nums, vector<int> &arr, vector<vector<int>> &ans){
        if(idx == n){
            ans.push_back(arr);
            return;
        }
        //path where we take the element
        arr.push_back(nums[idx]);
        getAll(idx+1,n,nums,arr,ans);
        arr.pop_back();
        //path where we ignore the element
        for(int i=idx+1;i<n;i++){
            if(nums[i] != nums[idx]){
                getAll(i,n,nums,arr,ans);
                return;
            }
        }
        //case if array skips because of all duplicates after a point till the end
        // eg- [1,2,2,2,2]
        getAll(n,n,nums,arr,ans);
        
    }
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        //your code goes here
        vector<int> arr;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        getAll(0,nums.size(),nums,arr,ans);
        return ans;
    }
};