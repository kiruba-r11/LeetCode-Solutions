class Solution {
public:
    int maxUniqueSplit(string s) {
        
        /*
        
        O(Nlog(N)) time and O(26) space complexity
        Idea -> Backtracking or Bit Manipulations
        
        */
        
        int n = s.size() , start = 0 , end = (1 << n) - 1 , ans = 0;
        bool check = true;
        
        string temp = "";
        set <string> dup; 

        for(int i = start; i <= end; i++) {
            temp = "";
            check = true;
            for(int j = n - 1 , k = 0; j >= 0; j-- , k++) {
                temp += s[k];
                if(i & (1 << j)) {
                    if(dup.count(temp) == 0) {
                        dup.insert(temp);
                        temp = "";
                    } else {
                        check = false;
                        break;
                    }
                }
            }
            if(check) {
                ans = max(ans , (int)dup.size());
            }
            dup.clear();
        }
        
        return ans;
    }
};