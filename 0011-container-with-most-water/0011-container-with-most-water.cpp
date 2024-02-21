class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0 , j = n - 1;
        int maxans = 0;
        while(i < j) {
            int curans = min(height[i] , height[j]) * (j - i);
            maxans = max(curans , maxans);
            
            if(height[i] <= height[j]) i++;
            else j--;
        }
        
        return maxans;
    }
};