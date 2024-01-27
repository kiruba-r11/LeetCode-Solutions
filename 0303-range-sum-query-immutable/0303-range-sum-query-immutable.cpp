class NumArray {
public:
    vector <int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);
        
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] += prefix[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right] - (left >= 1 ? prefix[left - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */