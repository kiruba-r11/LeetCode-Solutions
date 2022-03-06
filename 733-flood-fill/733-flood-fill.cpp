class Solution {
public:
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    
    void dfs(vector <vector <int>> &image , int i , int j , int newColor , int oldColor) {
        
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != oldColor) return;
        
        image[i][j] = newColor;
        
        for(auto dir: dirs) {
            int ni = dir.first + i;
            int nj = dir.second + j;
            
            dfs(image , ni , nj , newColor , oldColor);
        }
    
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        /*
        
        O(N) time and space complexity
        Idea -> DFS or BFS
        
        */
        
        int oldColor = image[sr][sc];
        if(oldColor != newColor)
            dfs(image , sr , sc , newColor , oldColor);
        
        return image;
    }
};