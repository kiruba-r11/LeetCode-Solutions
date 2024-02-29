class Solution {
public:
    bool valid(string &s , int start , int &cur , int sq) {
        
        if(start == s.size()) {
            return cur == sq;
        }
        
        string prefix = "";
        for(int i = start; i < s.size(); i++) {
            prefix += s[i];
            cur += stoi(prefix);
            if(valid(s , i + 1 , cur , sq)) return true;
            cur -= stoi(prefix);
        }
        
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int sq = i * i;
            string sqs = to_string(sq);
            int cur = 0;
            if(valid(sqs , 0 , cur , i)) ans += sq;
        }
        return ans;
    }
};