class Solution {
public:
    vector<int> nse(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            int curr = nums[i];
            while(!st.empty() && nums[st.top()] >= curr){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            int curr = nums[i];
            while(!st.empty() && nums[st.top()] > curr){
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    int calculateMaxArea(vector<int> &h){
        vector<int> NSE = nse(h);
        vector<int> PSE = pse(h);
        int n = h.size();
        int maxArea = 0;
        for(int i=0;i<n;i++){
            int area = h[i] * (NSE[i]-PSE[i]-1);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> prefixSum(n,vector<int>(m,0));
        //we traverse column wise 
        for(int j=0;j<m;j++){
            int sum = 0;
            for(int i=0;i<n;i++){
                if(matrix[i][j] == '0'){
                    prefixSum[i][j] = 0;
                    sum = 0;
                }
                else{
                    sum += matrix[i][j] - '0';
                    prefixSum[i][j] = sum;
                }
            }
        }
        int areaMax = 0;
        for(int i=0;i<n;i++){
            int area = calculateMaxArea(prefixSum[i]);
            areaMax = max(areaMax, area);
        }
        return areaMax;
    }
};