class Solution {
public:
    bool ispossible(vector <int> &nums , int k , int allow) {
        
        int n = nums.size();
        int i = 0 , j = 0;
        unordered_map <int , int> hash;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= k) {
                hash[nums[j]]++;
                if(window == k) {
                    bool check = true;
                    for(auto elem: hash) {
                        if(elem.second > allow) {
                            check = false;
                            break;
                        }
                    }
                    if(check) return true;
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
    
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0 , high = n;
        int ans = low;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool condition = ispossible(nums , mid , k);
            if(condition) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};