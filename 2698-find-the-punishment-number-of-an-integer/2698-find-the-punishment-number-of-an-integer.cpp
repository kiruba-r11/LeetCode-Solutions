class Solution {
public:
    
    bool partition(string &str , int i , string &cur , int sum , int num) {
        
        if(i == str.size()) {
            if(to_string(sum + stoi(cur)) == to_string(num)) return true;
            return false;
        }
        
        cur.push_back(str[i]);
        if(partition(str , i + 1 , cur , sum , num)) return true;
        cur.pop_back();
        
        string temp = "";
        temp.push_back(str[i]);
        if(partition(str , i + 1 , temp , sum + (cur.size() ? stoi(cur) : 0) , num)) return true;
        temp = cur;
        
        return false;
    }
    
    bool solve(int n) {
        int val = n * n;
        string val_str = to_string(val);
        
        int sum = 0;
        string cur = "";
        return partition(val_str , 0 , cur , sum , n);
    }
    
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(solve(i)) {
                ans += i * i;
            }
        }
        return ans;
    }
};