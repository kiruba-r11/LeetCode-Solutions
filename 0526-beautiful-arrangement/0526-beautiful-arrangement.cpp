class Solution {
public:
    int cnt = 0;
    void construct(int n , int idx , unordered_map <int , int> &hash) {
        
        if(n + 1 == idx) {
            cnt++;
            return; 
        }
        
        for(int i = 1; i <= n; i++) {
            if(hash[i] == false) {
                if(i % idx == 0 || idx % i == 0) {
                    hash[i] = true;
                    construct(n , idx + 1 , hash);
                    hash[i] = false;
                }
            }
        }
    }
    
    int countArrangement(int n) {
        unordered_map <int , int> hash;
        construct(n , 1 , hash);
        return cnt;
    }
};