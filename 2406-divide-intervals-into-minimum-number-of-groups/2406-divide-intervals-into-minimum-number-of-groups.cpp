class Solution {
public:
    int minGroups(vector<vector<int>>& nums) {
        priority_queue <int , vector <int> , greater <int>> pq;
        sort(nums.begin() , nums.end());
        
        for(auto i: nums) {
            if(!pq.empty() && pq.top() < i[0]) pq.pop();
            pq.push(i[1]);
        }
        
        return pq.size();
    }
};
