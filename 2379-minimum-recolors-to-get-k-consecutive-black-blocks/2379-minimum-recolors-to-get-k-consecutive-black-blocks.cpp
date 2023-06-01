class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0 , j = 0;
        int white = 0;
        int ans = n;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                if(blocks[j] == 'W') white++;
                
                if(window == k) {
                    ans = min(ans , white);
                }
                
                j++;
            } else {
                if(blocks[i] == 'W') white--;
                i++;
            }
        }
        
        return ans;
    }
};