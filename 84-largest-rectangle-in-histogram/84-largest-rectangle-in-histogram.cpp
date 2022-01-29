class Solution {
private:
    
    void findNSL(vector <int> &nsl , vector <int> &heights) {
        
        int n = heights.size();
        
        // Monotonic stack to store indices of elements in increasing order
        stack <int> s;
        
        s.push(0);
        
        for(int i = 1; i < n; i++) {
            
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            
            if(!s.empty()) nsl[i] = s.top();
            
            s.push(i);
        }
    }
    
    void findNSR(vector <int> &nsr , vector <int> &heights) {
        
        int n = heights.size();
        
        // Monotonic stack to store indices of elements in increasing order
        stack <int> s;
        
        s.push(n - 1);
        
        for(int i = n - 2; i >= 0; i--) {
            
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();
            
            if(!s.empty()) nsr[i] = s.top();
            
            s.push(i);
        }  
    }
        
public:
    
    
    int largestRectangleArea(vector<int>& heights) {
        
        /*
        
        Complexity -> O(N) time and O(N) monotonic stack space
        Idea -> Using monotonic stack
        
        */
        
        int n = heights.size() , ans = 0;
        
        vector <int> nsl(n , -1) , nsr(n , n);
        
        // Finding NSL -> O(N) time and space
        findNSL(nsl , heights);
        
        // Finding NSR -> O(N) time and space
        findNSR(nsr , heights);
        
        for(int i = 0; i < n; i++) {
            
            // For a current point, the height will extend towards left and right until a point is found which is of lesser height that the current one.
            
            // To find the lesser point on both sides we use NSL (Nearest Smallest to Left) and NSR (Nearest Smallest to Right). All points between these two will have the height greater than or equal to the current point.
            
            ans = max(ans , ((nsr[i] - nsl[i]) - 1) * heights[i]);
            
        }
        
        return ans;
        
    }
};