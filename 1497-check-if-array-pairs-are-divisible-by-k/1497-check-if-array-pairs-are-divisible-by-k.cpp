class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        map <int , int> hash;
        
        for(int i = 0; i < n; i++) {
            if((k + arr[i] % k) % k != 0) hash[(k + arr[i] % k) % k]++;
        }
        
        for(auto i: hash) {
            int elem = i.first;
            int count = i.second;
            int pairelem = k - elem;
            int paircount = hash[pairelem];
            
            if(elem == pairelem) {
                if(count & 1) return false;
            } else {
                if(count != paircount) return false;
            }
        }
        
        return true;
    }
};