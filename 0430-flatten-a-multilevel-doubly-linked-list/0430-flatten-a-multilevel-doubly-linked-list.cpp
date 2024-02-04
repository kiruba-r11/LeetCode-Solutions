/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void flat(Node* head) {
        
        if(!head) return;
        
        Node* temp = head;
        while(temp) {
            if(temp->child != NULL) {
                
                flat(temp->child);
                Node* tail = temp->child;
                while(tail && tail->next) {
                    tail = tail->next;
                }
                
                Node* next = temp->next;
                
                temp->next = temp->child;
                temp->child->prev = temp;
                
                tail->next = next;
                if(next) next->prev = tail;
                
                temp->child = NULL;
                temp = next;
                
            } else temp = temp->next;
        }
        
    }
    Node* flatten(Node* head) {
        flat(head);
        return head;
    }
};