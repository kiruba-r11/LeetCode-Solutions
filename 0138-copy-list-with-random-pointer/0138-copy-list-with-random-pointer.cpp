/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node* , Node*> old_to_new;
        
        Node* temp = head;
        Node* newHead = new Node(-1);
        Node* newTemp = newHead;
        
        while(temp) {
            Node* newNode = new Node(temp->val);
            old_to_new[temp] = newNode;
            newTemp->next = newNode;
            newTemp = newTemp->next;
            temp = temp->next;
        }
        
        temp = head;
        newTemp = newHead->next;
        
        while(temp) {
            newTemp->random = old_to_new[temp->random];
            newTemp = newTemp->next;
            temp = temp->next;
        }
        
        return newHead->next;
    }
};