class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector <pair <int , int>> vp(n);
        for(int i = 0; i < n; i++) {
            vp[i] = {abs(arr[i] - x) , arr[i]};
        }
        
        sort(vp.begin() , vp.end());
        
        int i = 0;
        vector <int> ans(k);
        while(k--) {
            ans[i] = vp[i].second;
            i++;
        }
        
        sort(ans.begin() , ans.end());
        return ans;
    }
};