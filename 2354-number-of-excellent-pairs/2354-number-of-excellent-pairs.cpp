class Solution {
public:
    int countSetBits(int num) {
    
        int cnt = 0;
        while(num) {
            cnt++;
            num = num & (num - 1);
        }
        
        return cnt;
    }
    
    int bs(vector <int> &a , int low , int high , int key) {
        int ans = a.size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(a[mid] >= key) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        // remove duplicates
        vector <int> num;
        for(auto i: unordered_set <int> (nums.begin() , nums.end())) 
            num.push_back(i);
        
        // set(x & y) + set(x | y) = set(x) + set(y)
        vector <int> setBits;
        for(auto i: num) {
            setBits.push_back(countSetBits(i));
        }
        
        sort(setBits.begin() , setBits.end());
        
        // binary search for set(y), where set(y) >= k - set(x)
        
        int n = setBits.size();
        long long ans = 0;
        
        for(auto i: setBits) {
            ans += n - bs(setBits , 0 , n - 1 , k - i);
        }
        
        return ans;
    }
};