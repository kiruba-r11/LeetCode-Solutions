class Solution {
public:
    int score(vector <int> &students , vector <int> &mentors) {
        int cnt = 0;
        for(int i = 0; i < students.size(); i++) {
            if(students[i] == mentors[i]) cnt++;
        }
        
        return cnt;
    }
    
    int ans = 0;
    void maxSum(vector <vector <int>> &students , int idx , vector <vector <int>> &mentors , vector <int> &taken , int &cur) {
        
        if(idx == students.size()) {
            ans = max(ans , cur);
            return;
        }
        
        for(int i = 0; i < mentors.size(); i++) {
            if(taken[i] == false) {
                taken[i] = true;
                int match = score(students[idx] , mentors[i]);
                cur += match;
                
                maxSum(students , idx + 1 , mentors , taken , cur);
                
                cur -= match;
                taken[i] = false;
            }
        }
        
    } 
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = mentors.size();
        vector <int> taken(n);
        int cur = 0;
        
        maxSum(students , 0 , mentors , taken , cur);
        return ans;
    }
};