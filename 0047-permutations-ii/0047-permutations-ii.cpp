class Solution {
public:
    vector <vector <int>> ans;
    void permute(unordered_map <int , int> &hash , int n , vector <int> &cur) {
        
        if(n == cur.size()) {
            ans.push_back(cur);
            return;
        }
        
        for(auto i: hash) {
            if(i.second != 0) {
                hash[i.first]--;
                cur.push_back(i.first);
                
                permute(hash , n , cur);
                
                cur.pop_back();
                hash[i.first]++;
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector <int> cur;
        unordered_map <int , int> hash;
        for(auto i: nums) hash[i]++;
        permute(hash , nums.size() , cur);
        return ans;
    }
};
