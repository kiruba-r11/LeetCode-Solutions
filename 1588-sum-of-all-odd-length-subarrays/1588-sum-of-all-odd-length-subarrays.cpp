class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        
        /*
        
        O(N ^ 2) time and O(N) space complexity
        Idea -> Produce all subarrays and find the sum of subarray with odd length using precomputations
        
        */
        
        int n = arr.size();
        int sum = 0;
        vector <int> prefix(n);
        
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + arr[i];
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int len = j - i + 1;
                if(len & 1) {
                    sum += prefix[j] - (i >= 1 ? prefix[i - 1] : 0);
                }
            }
        }
            
        return sum;
    }
};