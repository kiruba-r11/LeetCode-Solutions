class Solution {
public:
    int maxArea(int h, int v, vector<int>& hor, vector<int>& ver) {
        
        sort(hor.begin() , hor.end());
        sort(ver.begin() , ver.end());
        
        int nh = hor.size() , nv = ver.size();
        int hmax = hor[0] , vmax = ver[0];
        
        for(int i = 1; i < nh; i++) {
            hmax = max(hmax , hor[i] - hor[i - 1]);    
        }
        hmax = max(hmax , h - hor[nh - 1]);
        
        for(int i = 1; i < nv; i++) {
            vmax = max(vmax , ver[i] - ver[i - 1]);    
        }
        vmax = max(vmax , v - ver[nv - 1]);
        
        int mod = 1e9 + 7;
        
        return (hmax * 1L * vmax) % mod;
    }
};
