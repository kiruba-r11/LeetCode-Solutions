class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        long long ans = 0;
        int mod = 1e9 + 7;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && arr[i] == arr[j]) j++;
            long long cnt = j - i;
            
            int start = i + 1;
            int end = n - 1;
            
            while(start < end) {
                
                int startj = start;
                while(startj < n && arr[startj] == arr[start]) startj++;
                long long cnts = startj - start;
                
                int endj = end;
                while(endj > i && arr[endj] == arr[end]) endj--;
                long long cnte = end - endj;
                
                int sum = arr[i] + arr[start] + arr[end];
                if(sum == target) {
                    // cout << arr[i] << " " << arr[start] << " " << arr[end] << endl;
                    // cout << cnt << " " << cnts << " " << cnte << endl;
                    // cout << "----" << endl;
                    
                    long long val = 1;
                    if(arr[i] != arr[start] && arr[start] != arr[end]) val = cnt * cnts * cnte;
                    else if(arr[i] != arr[start]) val = cnt * cnts * (cnts - 1) / 2;
                    else if(arr[start] != arr[end]) val = cnt * cnts * cnte / 2;
                    else val = cnt * (cnt - 1) * (cnt - 2) / 6;
                    
                    ans += val;
                    ans %= mod;
                    start = startj;
                    end = endj;
                } else if(sum < target) {
                    start = startj;
                } else {
                    end = endj;
                }
            }
            
            i = j - 1;
        }
        
        return (int)ans;
    }
};

// [1,1,2,2,3,3,4,4,5,5]
// 8
// [1,1,2,2,2,2]
// 5
// [2,1,3]
// 6
// [2,2,3,2]
// 7
// [1,1,2,2,2,2]
// 5