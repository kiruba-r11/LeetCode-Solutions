class Solution {
public:
    string ans = "";
    bool solve(int n , string &cur , map <string , int> &hash) {
    
        if(n == 0) {
            if(hash[cur] == 0) {
                ans = cur;
                return true;
            }
            return false;
        }
        
        cur += "0";
        if(solve(n - 1 , cur , hash)) return true;
        cur.pop_back();
        
        cur += "1";
        if(solve(n - 1 , cur , hash)) return true;
        cur.pop_back();
        
        return false;
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        map <string , int> hash;
        for(auto i: nums) {
            hash[i]++;
        }
        
        int n = nums[0].size();
        string cur = "";
        solve(n , cur , hash);
        
        return ans;
    }
};