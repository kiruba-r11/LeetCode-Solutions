class Solution {
public:
    int subtractProductAndSum(int n) {
        /*
        
        O(logN) time and O(1) space complexity
        Idea -> Basic Math
        
        */
        
        int prd = 1 , sum = 0;
        while(n > 0) {
            int rem = n % 10;
            prd *= rem;
            sum += rem;
            n /= 10;
        }
        
        return prd - sum;
    }
};