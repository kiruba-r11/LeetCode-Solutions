class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int i = 0 , j = n - 1;
        int score = 0 , ans = 0;
        
        sort(tokens.begin() , tokens.end());
        
        while(i <= j) {
            if(score == 0) {
                if(power >= tokens[i]) {
                    power -= tokens[i];
                    score++;
                    ans = max(ans , score);
                    i++;
                } else {
                    return ans;
                }
            } else {
                if(power >= tokens[i]) {
                    power -= tokens[i];
                    score++;
                    ans = max(ans , score);
                    i++;
                } else {
                    power += tokens[j];
                    score--;
                    j--;
                }
            }
        }
        
        return ans;
    }
};