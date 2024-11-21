class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.empty()){
            return "";
        }
        for(int i=0;i<strs[0].size();i++){
            char ch = strs[0][i];
            for(string s : strs){
                if(i==s.size() || s[i] != ch){
                    return res;
                }
            }
            res += ch;
        }
        return res;
    }
};