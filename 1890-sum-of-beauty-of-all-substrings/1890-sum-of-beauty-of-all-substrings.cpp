class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> mpp;
            for(int j=i;j<s.size();j++){
                mpp[s[j]]++;
                int most = 0, least = INT_MAX;
                for(auto it : mpp){
                    most = max(most,it.second);
                    least = min(least,it.second);
                }
                ans += most - least;
            }
        }
        return ans;
    }
};