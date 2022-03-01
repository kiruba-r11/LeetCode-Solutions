class Solution {
public:
    double average(vector<int>& salary) {
        
        /*
        
        O(N) (1-iteration) time and O(1) space complexity
        Idea -> Array Traversal
        
        */
        
        double sum = 0.0;
        int minElem = INT_MAX , maxElem = INT_MIN;
        int n = salary.size();
        
        for(int i = 0; i < n; i++) {
            sum += salary[i];
            minElem = min(minElem , salary[i]);
            maxElem = max(maxElem , salary[i]);
        }
        
        sum -= minElem;
        sum -= maxElem;
        
        double avg = sum / (n - 2);
        return avg;
    }
};