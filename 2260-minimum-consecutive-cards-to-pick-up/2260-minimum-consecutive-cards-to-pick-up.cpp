class Solution {
public:
    bool slide(vector <int> &nums , int k) {
    
        int n = nums.size();
        int i = 0 , j = 0;
        unordered_map <int , int> hash;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                hash[nums[j]]++;
                
                if(window == k) {
                    if(hash.size() != window) return true;
                }
                
                j++;
            } else {
                if(hash[nums[i]] == 1) {
                    hash.erase(nums[i]);
                } else {
                    hash[nums[i]]--;
                }
                
                i++;
            }
        }
        
        return false;
    }
    
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int low = 1 , high = n , ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool check = slide(cards , mid);
            if(check) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};