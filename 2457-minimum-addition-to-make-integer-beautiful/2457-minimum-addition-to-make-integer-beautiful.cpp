class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        int sum = 0;
        long long temp = n;
        while(temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }
        
        temp = n;
        string ans = "";
        int carry = 0;
        while(sum + carry > target) {
            int rem = temp % 10 + carry;
            int r = temp % 10;
            temp /= 10;
            int req = 0;
            carry = 0;
            if(rem != 0) {
                req = 10 - rem;
                carry = 1;
            }
            ans += to_string(req);
            sum -= r;
        }
        
        reverse(ans.begin() , ans.end());
        if(ans == "") ans += "0";
        return stoll(ans);
    }
};
