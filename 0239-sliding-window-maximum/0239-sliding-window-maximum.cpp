class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        //we need an open ended data structure to be able to maintain a window
        //thus we choose deque
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<n;i++){
            //first we check if dq is not empty and check if its a valid window
            if(!dq.empty() && dq.front() <= i - k){
                dq.pop_front();
            }
            //we check if the the current element is greater than existing greater in the window
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            //if all conditions match then we push the index into dqueue
            dq.push_back(i);
            //if we have and active window and it is maximum we put into ans
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};