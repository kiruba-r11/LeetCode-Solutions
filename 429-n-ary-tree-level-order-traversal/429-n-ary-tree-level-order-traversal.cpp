/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(!root) return {};
        
        vector <vector <int>> ans;
        queue <Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int count = q.size();
            vector <int> temp;
            for(int it = 0; it < count; it++) {
                Node* node = q.front();
                q.pop();
                
                temp.push_back(node->val);
                for(auto i: node->children) {
                    q.push(i);
                }
                
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};