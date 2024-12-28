class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int areaMax = 0;
        stack<int> st;
        //lets traverse through the array
        for(int i=0;i<n;i++){
            //if stack is not empty and the element on top is bigger than the next
            while(!st.empty() && heights[st.top()] >= heights[i]){
                //we store the index for area calculation
                int idx = st.top();
                st.pop();
                //set pse and nse
                int pse = !st.empty() ? st.top() : -1;
                int nse = i;
                //calculate area and set maximum area
                int area = heights[idx]*(nse-pse-1);
                areaMax = max(area,areaMax);
            }
            //put index into the stack
            st.push(i);
        }
        //if after iteration still elements are left,
        //we do another iteration and calculate areas for them
        while(!st.empty()){
            //store idx for calculation of area
            int idx = st.top();
            st.pop();
            //set nse and pse
            int pse = !st.empty() ? st.top() : -1;
            int nse = n;
            //calculate area and set maximum accordingly
            int area = heights[idx]*(nse-pse-1);
            areaMax = max(area,areaMax);
        }
        return areaMax;
    }
};