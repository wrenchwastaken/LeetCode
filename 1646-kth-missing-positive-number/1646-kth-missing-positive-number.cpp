class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        int temp = k;
        for(int i=0;i<arr.size();i++){
            if(arr[i] <= temp){
                temp++;
            }
        }
        return temp;
    }
};