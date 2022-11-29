class RandomizedSet {
public:
    vector <int> nums;
    unordered_map <int , int> hash;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hash.find(val) != hash.end()) return false;
        
        nums.push_back(val);
        hash[val] = nums.size() - 1;
        
        return true;
    }
    
    bool remove(int val) {
        if(hash.find(val) == hash.end()) return false;
        
        int last = nums[nums.size() - 1];
        nums[hash[val]] = last;
        nums.pop_back();
        
        hash[last] = hash[val];
        hash.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */