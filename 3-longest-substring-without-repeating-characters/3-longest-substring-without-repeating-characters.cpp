class Solution {
public:
    bool solve(string &s , int len) {
    
        int start = 0 , end = 0 , n = s.size();
        vector <int> hash(127 , 0);
        
        while(end < n) {
            int window = end - start + 1;
            if(window <= len) {
                hash[s[end]]++;
                
                if(window == len) {
                    bool check = true;
                    for(auto i: hash) {
                        if(i > 1) {
                            check = false;
                            break;
                        }
                    }
                    if(check) return true;
                }
                
                end++;
            } else {
                hash[s[start]]--;
                start++;
            }
        }
        
        return false;
    }
    
    int lengthOfLongestSubstring(string s) {
        
        /*
        
        O(127N * logN) time and O(1) space complexity
        Idea -> Binary Search (on window size) + Sliding Window (fixed window size)
        
        */
        
        int low = 0 , high = s.size() , ans = 0;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            bool check = solve(s , mid);
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