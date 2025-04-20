class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count = 0;
        unordered_map<int, int> mpp;
        for(int num : answers){
            mpp[num]++;
        }
        for(auto it : mpp){
            count += ceil((double)it.second/(it.first + 1)) * (it.first + 1);
        }
        return count;
    }
};