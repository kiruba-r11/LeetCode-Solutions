class Solution {
public:
    bool bs(vector <int> &nums , int key) {
        int n = nums.size();
        int low = 0 , high = n - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] == key) return true;
            if(nums[mid] < key) low = mid + 1;
            else high = mid - 1;
        }
        
        return false;
    }
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        
        int suma = 0 , sumb = 0;
        int na = a.size() , nb = b.size();
        for(int i = 0; i < na; i++) suma += a[i];
        for(int i = 0; i < nb; i++) sumb += b[i];
        
        int required = (suma + sumb) / 2;
        int deficita = required - suma;

        for(int i = 0; i < na; i++) {
            if(bs(b , deficita + a[i])) return {a[i] , deficita + a[i]};
        }
        
        return {-1 , -1};
    }
};
