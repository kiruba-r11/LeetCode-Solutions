class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
//         Hurray! Its a classic HEAP problem, with slight variation of Connect ropes to minimise cost
        
        
        priority_queue <int> max_heap;
        for(auto i: stones) {
            max_heap.push(i);
        }
        
        while(max_heap.size() > 1) {
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();
            int diff = abs(x - y);
            if(diff != 0) {
                max_heap.push(diff);
            }
        }
        
        return max_heap.size() == 0 ? 0 : max_heap.top();
    }
};