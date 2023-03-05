class Solution {
public:
    int passThePillow(int n, int time) {
        int start = 1 , dir = 1;
        while(time--) {
            start += dir;
            if(start == 1 || start == n) dir *= -1;
        }
        
        return start;
    }
};