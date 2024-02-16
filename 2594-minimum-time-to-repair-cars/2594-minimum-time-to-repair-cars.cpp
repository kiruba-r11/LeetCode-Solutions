class Solution {
public:
    long long sqrt(long long num) {
        long long low = 1 , high = num;
        long long ans = low;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(mid <= num / mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
    
    bool condition(vector <int> &nums , int cars , long long time) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > time) return false;
            long long x = sqrt(time / nums[i]);
            cars -= x;
            
            if(cars <= 0) return true;
        }
        
        return false;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin() , ranks.end());
        long long low = 1 , high = 100 * 1LL * cars * 1LL * cars;
        long long ans = high;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(condition(ranks , cars , mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};