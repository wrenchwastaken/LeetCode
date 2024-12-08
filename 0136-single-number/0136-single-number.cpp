class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        //your code goes here
        int XOR = 0;
        for(int i=0;i<nums.size();i++){
            XOR ^= nums[i];
        }
        return XOR;
    }
};