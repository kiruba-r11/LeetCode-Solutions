class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int num = target / n;
        
        sort(arr.begin() , arr.end());
        int ans = arr[n - 1];
        int prefix = 0;
        int min_val = 0;
        int diff = INT_MAX;
        for(int i = 0; i < n; i++) {
            int cnt = n - i;
            int val1 = (target - prefix) / cnt;
            int val2 = (target - prefix) / cnt + ((target - prefix) % cnt != 0);

            int c1 = abs(target - (prefix + val1 * cnt));
            int c2 = abs(target - (prefix + val2 * cnt));
            // cout << prefix << endl;
            // cout << val1 << " val " << val2 << endl;
            // cout << c1 << " c " << c2 << endl;
            if(val1 <= arr[i] && val2 <= arr[i]) {
                if(val1 >= min_val && val2 >= min_val) {
                    if(diff > c1 && diff > c2) {
                        if(c1 <= c2) diff = c1 , ans = val1;
                        else diff = c2 , ans = val2;
                    } else if(diff > c1) {
                        diff = c1;
                        ans = val1;
                    } else if(diff > c2) {
                        diff = c2;
                        ans = val2;
                    }
                } else if(val1 >= min_val) {
                    if(diff > c1) diff = c1 , ans = val1;
                } else if(val2 >= min_val) {
                    if(diff > c2) diff = c2 , ans = val2;
                }
            } else if(val1 <= arr[i]) {
                if(val1 >= min_val) {
                    if(diff > c1) diff = c1 , ans = val1;
                }
            } else if(val2 <= arr[i]) {
                if(val2 >= min_val) {
                    if(diff > c2) diff = c2 , ans = val2;
                }
            } 
            // cout << ans << " ans : diff " << diff << endl;
            prefix += arr[i]; 
            min_val = arr[i];
        }
        
        return ans;
    }
};