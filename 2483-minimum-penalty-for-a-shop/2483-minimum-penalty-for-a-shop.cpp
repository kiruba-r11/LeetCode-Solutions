class Solution {
public:
    int bestClosingTime(string customer) {
        int tyes = 0 , tno = 0;
        int pyes = 0 , pno = 0;
        
        int n = customer.size();
        int maxpenalty = INT_MAX;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(customer[i] == 'Y') tyes++;
            else tno++;
        }
        
        for(int i = 0; i <= n; i++) {
            
            int penalty = tyes - pyes + pno;

            if(penalty < maxpenalty) {
                maxpenalty = penalty;
                ans = i;
            }
            
            if(i != n) {
                if(customer[i] == 'Y') pyes++;
                else pno++;
            }
        }
        
        return ans;
    }
};