class Solution {
public:
    int reqDays(vector<int>& weights, int d){
        int days = 1, load = 0;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > d){
                days += 1;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = accumulate(weights.begin(),weights.end(),0);
        while(l<=r){
            int mid = l +(r-l)/2;
            if(reqDays(weights,mid) <= days){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};