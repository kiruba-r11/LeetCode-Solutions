class Solution {
public:
    string ans = "";
    bool findBinary(string &cur , int n , unordered_map <string , int> &cache) {
        
        if(n == 0) {
            if(cache[cur] == 0) {
                ans = cur;
                return true;
            }
            return false;
        }
        
        cur.push_back('0');
        if(findBinary(cur , n - 1 , cache)) return true;
        cur.pop_back();

        cur.push_back('1');
        if(findBinary(cur , n - 1 , cache)) return true;
        cur.pop_back();

        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        unordered_map <string , int> cache;
        for(auto i: nums) cache[i]++;
        
        string cur = "";
        findBinary(cur , nums.size() , cache);
        return ans;
    }
};