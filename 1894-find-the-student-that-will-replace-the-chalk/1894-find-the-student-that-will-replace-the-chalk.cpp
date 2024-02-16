class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int n = chalk.size();
        
        for(int i = 0; i < n; i++) {
            sum += chalk[i];
        }
        
        int cnt = k / sum;
        k = k - sum * 1LL * cnt;

        for(int i = 0; i < n; i++) {
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }
        
        return -1;
    }
};