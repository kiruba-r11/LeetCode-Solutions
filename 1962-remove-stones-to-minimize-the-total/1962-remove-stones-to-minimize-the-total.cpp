class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue <int> pq;
        for(auto i: piles) pq.push(i);
        
        while(pq.size() && k-- > 0) {
            int elem = pq.top();
            pq.pop();
            elem -= elem / 2;
            if(elem > 0) pq.push(elem);
        }
        
        int sum = 0;
        while(pq.size()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
          
    }
};