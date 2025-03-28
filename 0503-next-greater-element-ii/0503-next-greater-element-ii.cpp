class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = 2*n-1;i>=0;i--){
            //actual index
            int idx = i % n;
            int curr = nums[idx];
            //maintaining the monotonic stack
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            //check if i is in bound before circle
            if(i<n){
                //if i inbound check if stack is not empty
                if(st.empty()){
                    ans[i] = -1;
                }
                //if stack is not empty then tag ans
                else{
                    ans[i] = st.top();
                }
            }
            st.push(curr);
        }
        return ans;
    }
};