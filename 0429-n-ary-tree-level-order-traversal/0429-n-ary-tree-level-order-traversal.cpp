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
        queue <Node*> q;
        q.push(root);
        vector <vector <int>> ans;
        while(!q.empty()) {
            int count = q.size();
            vector <int> level;
            for(int it = 0; it < count; it++) {
                Node* node = q.front();
                q.pop();
                
                level.push_back(node->val);
                
                for(auto nodes: node->children) {
                    q.push(nodes);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};