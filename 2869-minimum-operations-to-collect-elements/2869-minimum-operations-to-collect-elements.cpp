class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector <int> hash(51);
        int steps = 0;
        int cnt = k;
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--) {
            if(hash[nums[i]] == 0 && nums[i] <= k) cnt--;
            hash[nums[i]] = 1;
            steps++;
            if(cnt == 0) return steps;
        }
        return steps;
    }
};