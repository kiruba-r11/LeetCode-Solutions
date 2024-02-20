class Solution {
public:
    int process(int n) {
    
        int val = 0;
        while(n) {
            int rem = n % 10;
            val = val + rem * rem;
            n = n / 10;
        }
        return val;
    }
    
    bool isHappy(int n) {
        int slow = n , fast = n;
        while(n != 1) {
            slow = process(slow);
            fast = process(process(fast));

            if(slow == 1 || fast == 1) return true;
            if(slow == fast) return false;
        }
        
        return true;
    }
};