class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector <int> ngr(n , -1);
        stack <int> s;
        
        for(int i = 2 * n - 1; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums[i % n]) s.pop();
            if(!s.empty()) ngr[i % n] = s.top();
            s.push(nums[i % n]);
        }
        
        return ngr;
    }
};