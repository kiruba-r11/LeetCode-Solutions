class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue <int> pq;
        int n = heights.size();
        
        for(int i = 1; i < n; i++) {
            bool check = false;
            if(heights[i] <= heights[i - 1]) continue;
            else {
                int req = heights[i] - heights[i - 1];
                if(bricks >= req) {
                    pq.push(req);
                    bricks -= req;
                    check = true;
                } else {
                    if(ladders > 0) {
                        ladders--;
                        int prevmax = pq.empty() ? 0 : pq.top();
                        if(prevmax > req) {
                            pq.pop();
                            bricks -= req;
                            bricks += prevmax;
                            pq.push(req);
                        } 
                        check = true;
                    }
                }
            }
            if(!check) return i - 1;
        }
        
        return n - 1;
    }
};