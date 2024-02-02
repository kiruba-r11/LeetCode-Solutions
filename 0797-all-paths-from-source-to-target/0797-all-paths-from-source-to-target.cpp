class Solution {
public:
    void findPath(vector <vector <int>> &graph , int src , vector <int> &cur_path , 
                  vector <vector <int>> &total_path) {
        
        if(src == graph.size() - 1) {
            cur_path.push_back(src);
            total_path.push_back(cur_path);
            cur_path.pop_back();
            return;
        }
    
        cur_path.push_back(src);
        
        for(auto adj: graph[src]) {
            findPath(graph , adj , cur_path , total_path);
        }
        
        cur_path.pop_back();
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <vector <int>> total_path;
        vector <int> cur_path;
        
        findPath(graph , 0 , cur_path , total_path);
        
        return total_path;
    }
};