/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int ans = 0;
    void dfs(Employee* root , unordered_map <int , Employee*> &mapping) {
        ans += root->importance;
        
        for(auto subs: root->subordinates) {
            dfs(mapping[subs] , mapping);
        }
    }
    int getImportance(vector<Employee*> emp, int id) {
        unordered_map <int , Employee*> mapping;
        int n = emp.size();
        for(int i = 0; i < n; i++) {
            mapping[emp[i]->id] = emp[i];
        }
        
        dfs(mapping[id] , mapping);
        return ans;
    }
};