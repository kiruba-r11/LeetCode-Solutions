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
                    if(hash.size() <= 2) return true;
                }
                
                j++;
            } else {
                if(hash[nums[i]] == 1) hash.erase(nums[i]);
                else hash[nums[i]]--;
                i++;
            }
        }
        
        return false;
    }
    
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int low = 0 , high = n , ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool check = slide(fruits , mid);
            if(check) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};