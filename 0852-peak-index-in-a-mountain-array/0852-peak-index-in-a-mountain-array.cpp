class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 0 , high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(mid == low) {
                if(arr[mid] > arr[mid + 1]) return mid;
                else low = mid + 1;
            } else if(mid == high) {
                if(arr[mid] > arr[mid - 1]) return mid;
                else high = mid - 1;
            } else {
                if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) return mid;
                if(arr[mid] > arr[mid + 1]) high = mid - 1;
                else low = mid + 1;
            }
        }
        return -1;
    }
};