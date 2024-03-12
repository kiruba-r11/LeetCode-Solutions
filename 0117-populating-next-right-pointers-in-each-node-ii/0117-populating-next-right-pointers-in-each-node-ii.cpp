/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        Node* newRoot = root;
        while(newRoot) {
            Node* sentinel = new Node(-1);
            Node* temp = sentinel;
            
            while(newRoot) {
                if(newRoot->left) {
                    temp->next = newRoot->left;
                    temp = temp->next;
                } 
                if(newRoot->right) {
                    temp->next = newRoot->right;
                    temp = temp->next;
                }
                newRoot = newRoot->next;
            }
            newRoot = sentinel->next;
        }
        return root;
    }
};