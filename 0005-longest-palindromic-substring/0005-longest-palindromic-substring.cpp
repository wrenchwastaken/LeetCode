class Solution {
public:
    int expand(string s, int l, int r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return (r-l-1);
    }
    string longestPalindrome(string s) {
        if(s.empty()){
            return "";
        }
        int n = s.size();
        int l = 0, r = 0;
        for(int i = 0;i<n;i++){
            int len1 = expand(s,i,i);
            int len2 = expand(s,i,i+1);
            int len = max(len1,len2);
            if(len>r-l){
                l = i - (len-1)/2;
                r = i + (len)/2;
            }
        }
        return s.substr(l,r-l+1);
    }
};