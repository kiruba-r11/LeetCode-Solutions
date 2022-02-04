class Solution {
public:
    
    void find_optimal_score(vector <vector <int>> &students , vector <vector <int>> &mentors , int index , vector <bool> &taken , int cur_score , int &optimal_score) {
        
        // If all students have been paired with their mentors, find the optimal pairing score
        if(index == students.size()) {
            optimal_score = max(optimal_score , cur_score);
            return;
        }
        
        for(int i = 0; i < mentors.size(); i++) {
            
            // For a current student, find to pair with mentors who are available and are not paired with other students
            if(taken[i] == false) {
                
                int curscore = 0;
                
                // Calculate the compatibility score
                for(int j = 0; j < mentors[i].size(); j++) {
                    if(students[index][j] == mentors[i][j]) curscore++;
                }
                
                // The mentor is not paired, so he/she can't be paired with other student
                taken[i] = true;
                
                // Explore for all other possiblities
                find_optimal_score(students , mentors , index + 1 , taken , cur_score + curscore , optimal_score);
                
                // Backtrack, and make this mentor free so that he/she can now pair with other students.
                // This is done, to find all possible pairings, and calculate the optimal score.
                taken[i] = false;
                
            }
        }
        
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        /*
        
        O(N! * M) time and O(N) space complexity
        Idea -> Backtracking
        
        */
        
        int index = 0 , cur_score = 0 , optimal_score = 0 , n = students.size();
        vector <bool> taken(n);
        
        find_optimal_score(students , mentors , index , taken , cur_score , optimal_score);
        
        return optimal_score;
    }
};