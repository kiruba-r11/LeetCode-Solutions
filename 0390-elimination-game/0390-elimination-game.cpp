class Solution {
public:
    int solve(int n , int diff , int head , int itr) {    
        if(n == 1) return head;
        return solve(n / 2 , diff * 2 , 
                    ((itr & 1) || ((itr & 1) == 0 && (n & 1))) ? 
                     head + diff : head ,
                    1 - itr);
    }
    
    int lastRemaining(int n) {
        return solve(n , 1 , 1 , 1);
    }
};