// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        vector <pair <int , int>> dirs = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
        int n = grid.size() , m = grid[0].size();
        int cnt = 0;
        queue <pair <int , int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i , j});
                else if(grid[i][j] == 1) cnt++;
            }
        }
        int t = -1;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                pair <int , int> node = q.front();
                q.pop();
                
                for(auto dir: dirs) {
                    int x = dir.first + node.first;
                    int y = dir.second + node.second;
                    
                    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) {
                        q.push({x , y});
                        cnt--;
                        grid[x][y] = 2;
                    }
                }
            }
            t++;
        }
        if(cnt != 0) return -1;
        return t;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends