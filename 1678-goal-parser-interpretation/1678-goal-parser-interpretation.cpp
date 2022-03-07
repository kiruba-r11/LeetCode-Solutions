class Solution {
public:
    string interpret(string command) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> String Manipulations
        
        */
        
        string ans = "";
        int n = command.size();
        
        for(int i = 0; i < n; i++) {
            if(command[i] == 'G') ans += 'G';
            else if(command[i] == '(') {
                if(command[i + 1] == ')') {
                    ans += 'o';
                    i++;
                } else {
                    ans += "al";
                    i += 3;
                }
            }
        }
        
        return ans;
    }
};