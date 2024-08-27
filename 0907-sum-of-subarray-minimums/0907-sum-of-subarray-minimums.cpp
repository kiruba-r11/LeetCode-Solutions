class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        int ans = 0;
        vector <int> nsr(n , n) , nsl(n , -1);
        
        stack <int> s1 , s2;
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            if(!s1.empty()) nsr[i] = s1.top();
            s1.push(i);
        }
        
        for(int i = 0; i < n; i++) {
            while(!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            }
            if(!s2.empty()) nsl[i] = s2.top();
            s2.push(i);
        }
            
        for(int i = 0; i < n; i++) {
            long long l = i - nsl[i];
            long long r = nsr[i] - i;
            
            ans = (ans % mod + (l * r * arr[i]) % mod) % mod;
        }
        
        return ans;    
    }
};