class Solution {
private: 
    // Recursive helper function to find combinations
    void func(int ind, int sum, vector<int> &nums, 
              vector<int> &candidates, vector<vector<int>> &ans) {
        // If the sum is zero, add the current combination to the result
        if(sum == 0) {
            ans.push_back(nums);
            return;
        }

        // If the sum is negative or we have exhausted the candidates, return
        if(sum < 0 || ind == candidates.size()) return; 

        // Include the current candidate
        nums.push_back(candidates[ind]); 

        // Recursively call with updated sum and next index
        func(ind + 1, sum - candidates[ind], nums, candidates, ans); 

        // Backtrack by removing the last added candidate
        nums.pop_back(); 

        // Skip duplicates: if not picking the current candidate, 
        // ensure the next candidate is different
        for(int i = ind + 1; i < candidates.size(); i++) {
            if(candidates[i] != candidates[ind]) {
                func(i, sum, nums, candidates, ans); 
                break; 
            }
        }
    }

public:
    // Main function to find all unique combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> nums; 

        // Sort candidates to handle duplicates
        sort(candidates.begin(), candidates.end()); 

        // Start the recursive process
        func(0, target, nums, candidates, ans);

        return ans; 
    }
};