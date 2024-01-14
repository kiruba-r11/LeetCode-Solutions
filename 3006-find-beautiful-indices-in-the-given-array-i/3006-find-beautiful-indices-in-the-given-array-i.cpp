class Solution {
public:
    bool match_substring(string &s , string &t , int start) {
        
        int n = s.size();
        int m = t.size();
        int cnt = 0;
        
        for(int i = start , j = 0; i < n && j < m; i++ , j++) {
            if(s[i] != t[j]) return false;
            cnt++;
        }
        
        if(cnt != t.size()) return false;
        
        return true;
    }
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.size();
        vector <int> collect_a , collect_b;
        
        for(int i = 0; i < n; i++) {
            if(match_substring(s , a , i)) collect_a.push_back(i);
            if(match_substring(s , b , i)) collect_b.push_back(i);
        }
        
        vector <int> ans;
        int m = collect_a.size();
        for(int i = 0; i < m; i++) {
            int low = 0 , high = collect_b.size() - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                int val = abs(collect_b[mid] - collect_a[i]);
                if(val <= k) {
                    ans.push_back(collect_a[i]);
                    break;
                } else if(collect_b[mid] < collect_a[i]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return ans;
        
    }
};