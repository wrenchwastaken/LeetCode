class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        //we traverse through the nums
        for(int i=0;i<n;i++){
            //check if dq is non and empty and it is has a valid window element on top or not
            if(!dq.empty() && dq.front() <= (i-k)){
                dq.pop_front();
            }
            //maintain a monotonic stack as dq
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            //put index into dq
            dq.push_back(i);
            //check if first window has happened and ans needs to pushed
            if(i >= (k-1)){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};