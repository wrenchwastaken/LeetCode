class Solution {
public:
    bool checkValid(char open, char close){
        if((open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        int n = s.size();
        if(n % 2 != 0){
            return false;
        }
        stack<char> st;
        for(int i=0;i<n;i++){
            //if its an opening bracket, we put into stack
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            //otherwise we compare stack's top and to close
            else{
                //if stack is empty then not possible
                if(st.empty()){
                    return false;
                }
                //take top character,pop and compare
                char ch = st.top();
                st.pop();
                if(!checkValid(ch,s[i])){
                    return false;
                }
            }
        }
        return st.empty();
    }
};