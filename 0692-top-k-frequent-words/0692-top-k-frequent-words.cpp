class Solution {
public:
    class cmp {
        public:
            bool operator()(pair <int , string> &a , pair <int , string> &b) {
                if(a.first == b.first) return a.second.compare(b.second) > 0;
                return a.first < b.first;
            }
    };
        
    vector<string> topKFrequent(vector<string>& words, int k) {
        map <string , int> hash;
        for(auto i: words) {
            hash[i]++;
        }
        
        priority_queue <pair <int , string> , vector <pair <int , string>> , cmp> min_heap;
        for(auto it: hash) {
            min_heap.push({it.second , it.first});
            // if(min_heap.size() > k) min_heap.pop();
        }
        
        vector <string> res;
        while(k-- > 0) {
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};