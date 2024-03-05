class Solution {
public:
    // split it into k subsets with equal sum
    bool solve(vector <int> &jobs , int k , vector <int> &sub , int idx , int val) {
        
        if(idx == jobs.size()) {
            return true;
        }
        
        for(int i = 0; i < k; i++) {
            if(sub[i] + jobs[idx] <= val) {
                sub[i] += jobs[idx];
                if(solve(jobs , k , sub , idx + 1 , val)) return true;
                sub[i] -= jobs[idx];
            } 
            if(sub[i] == 0) break;
        }
        
        return false;
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin() , jobs.rend());
        int n = jobs.size();
        int low = jobs[0] , high = jobs[0] * n;
        int ans = high;
        while(low <= high) {
            vector <int> subs(k);
            int mid = low + (high - low) / 2;
            if(solve(jobs , k , subs , 0 , mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};