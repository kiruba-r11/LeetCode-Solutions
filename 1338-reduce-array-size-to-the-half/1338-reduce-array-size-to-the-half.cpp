class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map <int , int> hash;
        for(auto i: arr) {
            hash[i]++;
        }
        
        int size = arr.size();
        priority_queue <pair <int , int>> max_heap;
        for(auto it: hash) {
            max_heap.push({it.second , it.first});
        }
        int cnt = ((int)arr.size() % 2 != 0 ? arr.size() / 2 + 1: arr.size() / 2);
        int count = 0;
        int new_size = 0;
        while(true) {
            new_size += max_heap.top().first;
            count++;
            if(new_size >= cnt) {
                break;
            }
            max_heap.pop();
        }
        return count;
    }
};