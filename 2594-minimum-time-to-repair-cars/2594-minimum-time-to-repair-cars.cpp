class Solution {
public:
    bool solve(vector <int> &ranks , int cars , long long limit) {
        
        int n = ranks.size();
        for(int i = 0; i < n; i++) {
            
            int acccars = sqrt(limit / (long long)ranks[i]);
            if(acccars >= cars) return true;
            cars -= acccars;
            
        }
        
        return false;
    }
    
    
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin() , ranks.end());
        int n = ranks.size();
        
        long long low = 0 , high = ranks[n - 1] * 1LL * cars * cars;
        long long ans = 0;
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            bool check = solve(ranks , cars , mid);
            if(check) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};