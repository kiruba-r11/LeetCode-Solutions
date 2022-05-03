class Solution {
public:
    bool slide(vector <int> &nums , vector <bool> &prefix , vector <bool> &suffix , int k) {
    
        int i = 0 , j = 0 , n = nums.size() , minElem = INT_MAX , maxElem = INT_MIN;
        deque <int> minDq , maxDq;
        
        while(j < n) {
         
            int window = j - i + 1;
            if(window <= k) {
                
                while(!minDq.empty() && nums[minDq.back()] > nums[j]) {
                    minDq.pop_back();
                }
                
                minDq.push_back(j);
                
                while(!maxDq.empty() && nums[maxDq.front()] < nums[j]) {
                    maxDq.pop_back();
                }
                
                maxDq.push_back(j);
                
                if(window == k) {
                    
                    maxElem = nums[maxDq.front()];
                    minElem = nums[minDq.front()];
                    
                    bool pre = (i >= 1) ? prefix[i - 1] : true;
                    bool suf = (j < n - 1) ? suffix[j + 1] : true;
                    bool mini = (i >= 1) ? (minElem >= nums[i - 1]) : true;
                    bool maxi = (j < n - 1) ? (maxElem <= nums[j + 1]) : true;
                    
                    if(pre && suf && mini && maxi) return true; 
                } 
                
                j++;
            } else {
             
                if(minDq.front() == i) minDq.pop_front();
                if(maxDq.front() == i) maxDq.pop_front();
                
                i++;
            }
        }
        
        return false;
    }
    
    int slide(vector <int> &nums , vector <bool> &prefix , vector <bool> &suffix) {
    
        int i = 0 , j = 0 , n = nums.size() , minElem = INT_MAX , maxElem = INT_MIN;
        deque <int> minDq , maxDq;
        
        int ans = INT_MAX;
        
        while(j < n) {
         
            bool pre = (i >= 1) ? prefix[i - 1] : true;
            bool suf = (j < n - 1) ? suffix[j + 1] : true;
            
            while(!minDq.empty() && nums[minDq.back()] > nums[j]) {
                minDq.pop_back();
            }

            minDq.push_back(j);

            while(!maxDq.empty() && nums[maxDq.front()] < nums[j]) {
                maxDq.pop_back();
            }

            maxDq.push_back(j);
            
            maxElem = nums[maxDq.front()];
            minElem = nums[minDq.front()];

            bool mini = (i >= 1) ? (minElem >= nums[i - 1]) : true;
            bool maxi = (j < n - 1) ? (maxElem <= nums[j + 1]) : true;
                
            while(i < j && pre && suf && mini && maxi) {
             
                ans = min(ans , j - i + 1);
                
                if(minDq.front() == i) minDq.pop_front();
                if(maxDq.front() == i) maxDq.pop_front();

                i++;
                
                pre = (i >= 1) ? prefix[i - 1] : true;
                minElem = nums[minDq.front()];
                mini = (i >= 1) ? (minElem >= nums[i - 1]) : true;
            }  
            
            j++;
        }
        
        return ans;
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        vector <bool> prefix(n , false) , suffix(n , false);
        prefix[0] = suffix[n - 1] = true;
        
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] && (nums[i] >= nums[i - 1]);
        }
        
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] && (nums[i] <= nums[i + 1]);
        }
        
        if(prefix[n - 1]) return 0;
        
        return slide(nums , prefix , suffix);
        
        // int low = 0 , high = n , ans = n + 1;
        // while(low <= high) {
        //     int mid = low + (high - low) / 2;
        //     bool check = slide(nums , prefix , suffix , mid);
        //     if(check) {
        //         ans = mid;
        //         high = mid - 1;
        //     } else {
        //         low = mid + 1;
        //     }
        // }
        
        // return ans;
    }
};