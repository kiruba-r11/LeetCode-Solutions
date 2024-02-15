class Solution {
public:
    static bool cmp(pair <int , int> &a , pair <int , int> &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    
    int bs(vector <pair <int , int>> &vp , int key) {
        
        int n = vp.size();
        int low = 0 , high = n - 1;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(vp[mid].first <= key) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        if(ans != -1) return vp[ans].second;
        return 0;
    }
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int n = profit.size();
        vector <pair <int , int>> vp(n);
        
        for(int i = 0; i < n; i++) {
            vp[i] = {difficulty[i] , profit[i]};
        }
        
        sort(vp.begin() , vp.end() , cmp);
        
        int premax = vp[0].second;
        for(int i = 1; i < n; i++) {
            premax = max(premax , vp[i].second);
            vp[i].second = premax;
        }
        
        int m = worker.size();
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            ans += bs(vp , worker[i]);
        }
        
        return ans;
    }
};