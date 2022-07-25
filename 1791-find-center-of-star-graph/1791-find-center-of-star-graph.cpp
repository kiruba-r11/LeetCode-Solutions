class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map <int , int> hash;
        int n = 0;
        
        for(auto i: edges) n = max(n , max(i[0] , i[1]));
        
        for(auto i: edges) {
            hash[i[0]]++;
            hash[i[1]]++;
            
            if(hash[i[0]] == n - 1) return i[0];
            if(hash[i[1]] == n - 1) return i[1];
        }
        
        return -1;
    }
};