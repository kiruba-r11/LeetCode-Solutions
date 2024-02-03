class Solution {
public:
    vector <int> ans;
    void sameDiff(string &cur , int n , int k) {
        
        if(n == 0) {
            ans.push_back(stoi(cur));
            return;
        }
        
        int back = cur.back() - '0';
        
        if(k + back < 10) {
            cur.push_back((k + back) + '0');
            sameDiff(cur , n - 1 , k);
            cur.pop_back();
        }
        if(back - k >= 0) {
            if(k + back != back - k) {
                cur.push_back((back - k) + '0');
                sameDiff(cur , n - 1 , k);
                cur.pop_back();
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        string cur = "";
        for(int i = '1'; i <= '9'; i++) {
            cur.push_back(i);
            sameDiff(cur , n - 1 , k);
            cur.pop_back();
        }
        return ans;
    }
};