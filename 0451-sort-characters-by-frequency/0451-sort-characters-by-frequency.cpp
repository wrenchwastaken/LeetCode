class Solution {
public:
    string frequencySort(string s) {
        vector<vector<char>> buckets(s.size()+1);
        unordered_map<char, int> mpp1;
        for (int i = 0; i < s.size(); i++) {
            mpp1[s[i]]++;
        }
        for(auto it : mpp1){
            buckets[it.second].push_back(it.first);
        }
        string res;
        for(int i=buckets.size()-1;i>0;i--){
            if(buckets[i].empty()){
                continue;
            }
            for(char c : buckets[i]){
                res.append(i,c);
            }
        }
        return res;
    }
};