class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        //take max len and max idx
        int max_len = 1, max_idx = 0;
        //base case if nums len is 0
        //initiate dp and parent array
        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        if(n == 0){
            return {};
        }
        //loops to iterate on both dp and arr
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > max_len){
                max_len = dp[i];
                max_idx = i;
            }
        }
        vector<int> LDS;
        LDS.push_back(nums[max_idx]);
        while(parent[max_idx] != -1){
            max_idx = parent[max_idx];
            LDS.push_back(nums[max_idx]);
        }
        reverse(LDS.begin(),LDS.end());
        return LDS;
    }
};