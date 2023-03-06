class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 1;
        int i = 0;
        while(i < arr.size()) {
            if(arr[i] == start) {
                i++;
            } else {
                k--;
                if(k == 0) return start;
            }
            start++;
        }
        while(k != 1) start++ , k--;
        return start;
    }
};