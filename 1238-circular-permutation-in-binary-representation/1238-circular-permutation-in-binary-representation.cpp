class Solution {
public:
    int fpow(long long b , int p) {
        if(p == 0) return 1;
        if(p & 1) return b * fpow(b *  b , p / 2);
        return fpow(b * b , p / 2);
    }
    
    unordered_map <int , bool> hash;
    bool solve(int n , int start , vector <int> &ans) {
        
        if(ans.size() == fpow(2 , n)) {
            int num = ans[0] ^ ans.back();
            int bits = num & (num - 1);
            if(bits == 0) return true;
            return false;
        }
        
        for(int b = 0; b < n; b++) {
            int temp = start ^ (1 << b);
            if(hash.find(temp) == hash.end()) {
                hash[temp] = true;
                ans.push_back(temp);
                if(solve(n , temp , ans)) return true;
                ans.pop_back();
                hash.erase(temp);
            }
        }
        
        return false;
    }
    vector<int> circularPermutation(int n, int start) {
        vector <int> ans;
        ans.push_back(start);
        hash[start] = true;
        solve(n , start , ans);
        return ans;
    }
};