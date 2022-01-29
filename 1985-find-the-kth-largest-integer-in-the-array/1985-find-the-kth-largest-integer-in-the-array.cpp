// Comparator for priority queue
class cmp {
public:
    bool operator() (string &a , string &b) {
        int n = a.size() , m = b.size();
        if(n == m) return a > b;
        return n > m;
    }    
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue <string , vector <string> , cmp> pq;
        
        for(auto i: nums) {
            pq.push(i);
            
            // If the heap size reaches k + 1 , it means we are having (k + 1)th largest integer, but we want only kth, so we pop the (k + 1)th element from heap
            if(pq.size() > k) pq.pop();
        }
        
        return pq.top();
    }
};