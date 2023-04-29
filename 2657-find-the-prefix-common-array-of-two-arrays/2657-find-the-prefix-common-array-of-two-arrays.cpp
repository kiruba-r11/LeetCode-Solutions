class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector <int> ans(n);
        map <int , int> hash;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            hash[A[i]]++;
            hash[B[i]]++;
            
            if(A[i] == B[i]) {
                if(hash[A[i]] == 2 || hash[B[i]] == 2) cnt++;
            } else {
                if(hash[A[i]] == 2 && hash[B[i]] == 2) cnt += 2;
                else if(hash[A[i]] == 2 || hash[B[i]] == 2) cnt++;
            }

            ans[i] = cnt;
        }
        
        return ans;
    }
};