class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> mpp1;
        for(int i = 0;i<arr.size();i++){
            mpp1[arr[i]]++;
        }
        for(auto it : mpp1){
            int num = it.first;
            int count = it.second;
            if (mpp1.count(num * 2) && (num * 2 != num || count > 1)) {
                return true;
            }
            
            if (num % 2 == 0 && mpp1.count(num / 2) && (num / 2 != num || count > 1)) {
                return true;
            }
        }
        return false;
    }
};