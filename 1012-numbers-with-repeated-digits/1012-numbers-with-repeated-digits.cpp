class Solution {
public:
    int count(int n) {
        int cnt = 0;
        while(n) {
            n /= 10;
            cnt++;
        }
        return cnt;
    }
    
    int permute(int n) {
        
        if(n == 1) return 9;
        if(n == 2) return 9 * 9;
        
        long long ans = 9 * 9;
        int num = 8;
        for(int i = 0; i < n - 2; i++) {
            ans = ans * num;
            num--;
        }

        return (int)ans;
    }
    
    vector <int> helper(int n) {
        
        int idx = count(n) - 1;
        vector <int> temp(idx + 1);
        
        while(n) {
            temp[idx--] = n % 10;
            n /= 10;
        }
        
        return temp;
    }
    
    int cnt(int n , int length) {
        
        int start = 10 - n;
        long long ans = 1;
        
        for(int i = start; length > 0; i-- , length--) ans = ans * i;
        
        return (int)ans;
    }
    
    int less(int idx , int val , vector <int> &nums) {
        
        int cnt = 0;
        for(int i = 1; i < val; i++) {
            if(nums[i] == 0) cnt++;
        }
        
        if(idx != 0) {
            if(0 < val && nums[0] == 0) cnt++;
        }
        
        return cnt;
    }
    
    bool check(int n) {
        map <int , int> hash;
        while(n) {
            int rem = n % 10;
            if(hash[rem] != 0) return false;
            hash[rem] = 1;
            n /= 10;
        }
        return true;
    }
    
    int notRepeated(int n) {
        int digits = count(n);
        
        long long ans = 0;
        for(int i = 1; i < digits; i++) {
            ans += permute(i);
        }
        
        // cout << ans << endl;
        
        vector <int> temp = helper(n);
        vector <int> nums(10 , 0);
        
        int sz = temp.size();
        for(int i = 0; i < sz; i++) {
            int cnts = less(i , temp[i] , nums);
            ans += cnts * cnt(i + 1 , digits - (i + 1));
            // cout << cnts << " " << cnt(i + 1 , digits - (i + 1)) << endl;
            if(nums[temp[i]] == 1) break;
            nums[temp[i]] = 1;
        }
        
        if(check(n)) ans++;
        return (int) ans;
    }
    
    int numDupDigitsAtMostN(int n) {
        int ans = n - notRepeated(n);
        return ans;
    }
};