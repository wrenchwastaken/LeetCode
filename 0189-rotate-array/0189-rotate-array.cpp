class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Ensure k is within the bounds of the array siz
        if (k == 0) return;
        int temp[k];  // Temporary array to store the last k elements
         
        // Step 1: Store the last k elements in temp
        for(int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Step 2: Shift the first n - k elements to the right
        for(int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }

        // Step 3: Copy the k elements from temp back to the start of nums
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
