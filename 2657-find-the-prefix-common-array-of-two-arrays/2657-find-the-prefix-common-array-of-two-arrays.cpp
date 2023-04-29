class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector <int> ans(n);
        map <int , int> hash;
        
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            hash[B[i]]++;
            
            for(int j = 0; j <= i; j++) {
                if(hash[A[j]] != 0) cnt++;
            }
            ans[i] = cnt;
        }
        
        return ans;
    }
};