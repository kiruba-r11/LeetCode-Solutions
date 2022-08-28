class Solution {
public:
    vector <int> toposort(vector <vector <int>> &nums , int k) {
        
        int n = nums.size();
        
        vector <int> indeg(k + 1);
        vector <vector <int>> graph(k + 1);
        vector <int> topo;
        unordered_map <int , bool> hash;
        queue <int> q;
        
        for(int i = 0; i < n; i++) {
            indeg[nums[i][1]]++;
            graph[nums[i][0]].push_back(nums[i][1]);
        }

        for(int i = 1; i <= k; i++) {
            if(indeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                int node = q.front();
                q.pop();
                
                topo.push_back(node);
                hash[node] = true;
                
                for(auto adj: graph[node]) {
                    indeg[adj]--;
                    if(indeg[adj] == 0) q.push(adj);
                }
            }
        }
        
        for(int i = 1; i <= k; i++) {
            if(hash[i] == false) {
                topo.push_back(i);
            }
        }
        
        return topo;
    }
    
    int find(vector <int> &nums , int key) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == key) return i;
        }
        
        return -1;
    }
    
    bool isvalid(vector <vector <int>> &nums , vector <int> &topo) {
        
        for(auto i: nums) {
            int a_i = find(topo , i[0]);
            int b_i = find(topo , i[1]);
            
            if(a_i > b_i) return false;
        }
        
        return true;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        
        vector <int> toporow = toposort(row , k);
        vector <int> topocol = toposort(col , k);
        vector <vector <int>> grid(k , vector <int> (k));
        
        bool validrow = isvalid(row , toporow);
        bool validcol = isvalid(col , topocol);
        
        if(!validrow || !validcol) return {};
        
        for(int i = 0; i < k; i++) {
            int j = find(topocol , toporow[i]);
            grid[i][j] = toporow[i];
        }
        
        return grid;

    }
};