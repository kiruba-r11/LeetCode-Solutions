class Solution {
public:
    static bool cmp(int a , int b) {
        int a_bits = 0;
        int b_bits = 0;
        
        int a_temp = a;
        int b_temp = b;
        
        while(a_temp > 0) {
            a_bits++;
            a_temp = a_temp & (a_temp - 1);
        }
        
        while(b_temp > 0) {
            b_bits++;
            b_temp = b_temp & (b_temp - 1);
        }
        
        if(a_bits == b_bits) return a < b;
        
        return a_bits < b_bits;
    }
    vector<int> sortByBits(vector<int>& arr) {
        
        /*
        
        O(Nlog^2N) time and O(1) time complexity
        Idea -> Simulation
        
        */
        
        sort(arr.begin() , arr.end() , cmp);
        
        return arr;
    }
};