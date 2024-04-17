class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int m = 1e9 + 7;
        int ans = 0;
        map <int , int> hash;
        hash[sum] = 1;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            ans = (ans % m + hash[1 - sum % 2] % m) % m;
            hash[sum % 2]++;
        }
        
        return ans;
    }
};