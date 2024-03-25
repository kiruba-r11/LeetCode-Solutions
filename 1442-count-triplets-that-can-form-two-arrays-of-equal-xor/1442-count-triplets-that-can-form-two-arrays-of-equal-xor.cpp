class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int left = 0;
            for(int j = i; j < n; j++) {
                left = left ^ arr[j];
                int right = 0;
                for(int k = j + 1; k < n; k++) {
                    right = right ^ arr[k];
                    if(left == right) ans++;
                }
            }
        }
        
        return ans;
    }
};