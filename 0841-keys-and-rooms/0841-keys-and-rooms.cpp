class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector <bool> visited(n);
        
        queue <int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                int node = q.front();
                q.pop();
                
                for(auto i: rooms[node]) {
                    if(!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
        
        for(auto i: visited) if(!i) return false;
        return true;
    }
};