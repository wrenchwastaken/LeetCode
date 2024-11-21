class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,char> mpp1;
        unordered_map<char,char> mpp2;
        for(int i=0;i<s.size();i++){
            char s1 = s[i];
            char s2 = t[i];
            if((mpp1.count(s1) && mpp1[s1]!=s2) || (mpp2.count(s2) && mpp2[s2]!=s1)){
                return false;
            }
            mpp1[s1] = s2;
            mpp2[s2] = s1;
        }
        return true;
    }
};