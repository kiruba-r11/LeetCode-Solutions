class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> res;
        
        map <int , int> hash;
        for(auto i: nums) {
            hash[i]++;
        }
        
        priority_queue <pair <int , int> , vector <pair <int , int>> , greater <pair < int , int>>> min_heap;
        for(auto it: hash) {
            min_heap.push({it.second , it.first});
            if(min_heap.size() > k) min_heap.pop();
        }
        
        while(min_heap.size() != 0) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        
        return res;
    }
};