class Solution {
public:
    bool bs(vector <int> &arr , int key , int idx) {
        int high = arr.size() - 1;
        int low = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == key && mid != idx) return true;
            if(arr[mid] < key) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(bs(arr , 2 * arr[i] , i)) return true;
        }
        
        return false;
    }
};