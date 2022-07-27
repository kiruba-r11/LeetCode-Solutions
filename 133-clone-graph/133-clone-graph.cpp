/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void helper(Node* node , map <Node* , Node*> &hash) {
        
        queue <Node*> q;
        q.push(node);

        map <Node* , bool> visited;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                Node* n = q.front();
                q.pop();
                
                Node* newnode = new Node(n->val);
                hash[n] = newnode;
                
                for(auto i: n->neighbors) {
                    if(!visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
    }
    
    Node* clone(Node* node , map <Node* , Node*> &hash , map <Node* , bool> &visited) {
        
        if(!node) return node;
        if(visited[node]) return NULL;

        visited[node] = true; 

        for(auto i: node->neighbors) {
            hash[node]->neighbors.push_back(hash[i]);
            clone(i , hash , visited);
        }
        
        return hash[node];
    }
    
    Node* cloneGraph(Node* node) {
        
        if(!node) return node;
        
        map <Node* , Node*> hash;
        helper(node , hash);
        
        map <Node* , bool> visited;
        return clone(node , hash , visited);
    }
};