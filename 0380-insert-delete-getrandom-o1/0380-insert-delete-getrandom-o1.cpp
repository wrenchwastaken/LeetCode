class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,int> mpp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        //if value already exists then no need to insert again
        if(mpp.find(val) != mpp.end()){
            return false;
        }
        //if it does not exist
        nums.push_back(val);
        mpp[val] = nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        //if val doesnt not exist cannot remove
        if(mpp.find(val) == mpp.end()){
            return false;
        }
        //swap the last number with current val
        int idx = mpp[val];
        int lastElement = nums.back();
        nums[idx] = lastElement;
        mpp[lastElement] = idx;
        //remove from both array and map
        nums.pop_back();
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIdx = rand() % nums.size();
        return nums[randomIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */