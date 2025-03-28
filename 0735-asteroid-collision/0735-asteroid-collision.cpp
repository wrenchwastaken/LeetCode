class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> st;
        for(int i=0;i<n;i++){
            //putting asteroids into stack if moving right
            if(asteroids[i]>0){
                st.push_back(asteroids[i]);
            }
            //if moving left
            else{
                //sorting out negatives
                //maintain stack, if smaller then gets destroyed
                while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){
                    st.pop_back();
                }
                //if same then gets destroyed
                if(!st.empty() && st.back() == abs(asteroids[i])){
                    st.pop_back();
                }
                //if stack is empty or in same direction
                else if(st.empty() || st.back() < 0){
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};