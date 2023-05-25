class Solution {
public:
    bool isValid(int value , map <int , int> &hash) {
        if(value >= 0 && value <= 1000 && hash[value] == 0) return true;
        return false;
    }
    
    bool range(int value) {
        if(value < 0 || value > 1000) return true;
        return false;
    }
    
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue <int> q;
        q.push(start);
        
        int n = nums.size();
        int ans = 0;
        map <int , int> hash;
        hash[start]++;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                
                int node = q.front();
                q.pop();
                
                if(node == goal) return ans;
                
                for(int i = 0; i < n; i++) {
                    if(isValid(node + nums[i] , hash)) {
                        q.push(node + nums[i]);
                        hash[node + nums[i]]++;
                    } else {
                        if(range(node + nums[i])) if((node + nums[i]) == goal) return ans + 1;
                    }
                    
                    if(isValid(node - nums[i] , hash)) {
                        q.push(node - nums[i]);
                        hash[node - nums[i]]++;
                    } else {
                        if(range(node - nums[i])) if((node - nums[i]) == goal) return ans + 1;
                    }
                    
                    if(isValid(node ^ nums[i] , hash)) {
                        q.push(node ^ nums[i]);
                        hash[node ^ nums[i]]++;
                    } else {
                        if(range(node ^ nums[i])) if((node ^ nums[i]) == goal) return ans + 1;
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};