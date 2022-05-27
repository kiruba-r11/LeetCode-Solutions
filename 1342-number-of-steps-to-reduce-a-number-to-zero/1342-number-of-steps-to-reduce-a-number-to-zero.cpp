class Solution {
public:
    int numberOfSteps (int num) {
        int temp = num;
        int ans = 0;
        if(!num)
            return ans;
        int bits = 0;
        int setBits = 0;
        while(temp > 0) {
            bits++;
            if(temp & 1)
                setBits++;
            temp = temp >> 1;
        }
        cout << bits << " " << setBits << endl;
        ans = bits + setBits - 1;
        return ans;
    }
};