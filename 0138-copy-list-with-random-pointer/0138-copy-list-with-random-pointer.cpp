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
        // Approach:
        // Store the newly created nodes next to its corresponding nodes. So that, the newly created copy's random node 
        // will be the next of original random node 
        
        Node* temp = head;
        while(temp) {
            Node* newNode = new Node(temp->val);
            Node* next = temp->next;
            temp->next = newNode;
            newNode->next = next;
            temp = next;
        }
        
        temp = head;
        while(temp) {
            Node* originalRandom = temp->random;
            if(originalRandom) {
                Node* copyRandom = originalRandom->next;
                temp->next->random = copyRandom;
            }
            temp = temp->next->next;
        }
        
        Node* newHead = new Node(-1);
        Node* newTemp = newHead;
        temp = head;
        
        while(temp) {
            newTemp->next = temp->next;
            newTemp = newTemp->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        

        return newHead->next;
    }
};











