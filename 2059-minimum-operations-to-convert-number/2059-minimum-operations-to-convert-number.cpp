class Solution {
public:
    bool isValid(int value) {
        if(value >= 0 && value <= 1000) return true;
        return false;
    }
    
    int helper(int value , queue <int> &q , map <int , int> &hash , int goal , int ans) {
        
        if(isValid(value)) {
            if(hash[value] == 0) {
                q.push(value);
                hash[value]++;
            }
        } else {
            if(value == goal) return ans + 1;
        }
        
        return -1;
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
                    int v1 = helper(node + nums[i] , q , hash , goal , ans);
                    if(v1 != -1) return v1;
                    
                    int v2 = helper(node - nums[i] , q , hash , goal , ans);
                    if(v2 != -1) return v2;
                    
                    int v3 = helper(node ^ nums[i] , q , hash , goal , ans);
                    if(v3 != -1) return v3;
                }
            }
            ans++;
        }
        
        return -1;
    }
};