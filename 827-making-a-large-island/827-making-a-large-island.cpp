class Solution {
public:
    vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    
    void dfs(vector <vector <int>> &grid , int i , int j , int &ans) {
    
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return;
        
        ans++;
        grid[i][j] = -1;
        
        for(auto dir: dirs) {
            int x = dir.first + i;
            int y = dir.second + j;
            
            dfs(grid , x , y , ans);
        }
    }
    
    void dfsFill(vector <vector <int>> &grid , int board[500][500] , int i , int j , int ans , int temp) {
    
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != -1) return;
        
        grid[i][j] = ans;
        board[i][j] = temp;
        
        for(auto dir: dirs) {
            int x = dir.first + i;
            int y = dir.second + j;
            
            dfsFill(grid , board , x , y , ans , temp);
        }
    }
    
    bool inBound(int i , int j , int n , int m) {
        if(i < 0 || j < 0 || i >= n || j >= m) return false;
        return true;
    }
    
    int getUniqueSum(pair <int , int> &a , pair <int , int> &b , pair <int , int> &c , pair <int , int> &d) {
        
        unordered_map <int , int> hash;
        
        if(hash.find(a.second) == hash.end()) hash[a.second] = a.first;
        else hash[a.second] = max(hash[a.second] , a.first);
        
        if(hash.find(b.second) == hash.end()) hash[b.second] = b.first;
        else hash[b.second] = max(hash[b.second] , b.first);
        
        if(hash.find(c.second) == hash.end()) hash[c.second] = c.first;
        else hash[c.second] = max(hash[c.second] , c.first);
        
        if(hash.find(d.second) == hash.end()) hash[d.second] = d.first;
        else hash[d.second] = max(hash[d.second] , d.first);
        
        int sum = 0;
        for(auto i: hash) {
            sum += i.second;
        }
        
        return sum;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int temp = 1;
        
        int board[500][500];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    
                    int ans = 0;
                    dfs(grid , i , j , ans);
                    dfsFill(grid , board , i , j , ans , temp);
                    temp++;
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    
                    pair <int , int> up , down , left , right;
                    
                    if(inBound(i - 1 , j , n , m)) up = {grid[i - 1][j] , board[i - 1][j]};
                    if(inBound(i + 1 , j , n , m)) down = {grid[i + 1][j] , board[i + 1][j]};
                    if(inBound(i , j - 1 , n , m)) left = {grid[i][j - 1] , board[i][j - 1]};
                    if(inBound(i , j + 1 , n , m)) right = {grid[i][j + 1] , board[i][j + 1]};
                    
                    int sum = getUniqueSum(up , down , left , right) + 1;
                    ans = max(ans , sum);
                    
                } else {
                    ans = max(ans , grid[i][j]);
                }
            }
        }
        
        return ans;
    }
};