/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void deleteNodes(map <int , ListNode*> &hash , ListNode* start , ListNode* end , int sum) {
        
        // Start is the previous node to the node which we want to delete
        // End is the node till which we have to delete
        
        ListNode* temp = start->next;
        start->next = end->next;
        
        while(temp != start->next) {
            
            // If this is the node that we are deleting than it has to be deleted in hash if its the first occurence in hash
            
            sum += temp->val;
            
            if(hash[sum] == temp)
                hash[sum] = NULL;
            
            end = temp->next;
            temp = end;
        }
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        /*
        
        O(N) time and space complexity
        Idea -> Prefix sum hashing with sentinel node of Linked Lists
        
        */
        
        // Using a sentinel node technique, always the best to solve Linked Lists problems to avoid NULL-Pointer Exceptions
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
       
        // Hashing to find a zero sum sublist
        map <int , ListNode*> hash;
        hash[0] = newHead;
        
        int sum = 0;
        
        ListNode* temp = head;
        
        while(temp) {
            sum += temp->val;

            if(hash[sum] == NULL) {
                hash[sum] = temp;
            } else {
                
                // If this sum already exists, then the sum of sublists from that point which gave this sum to this point is zero
                
                ListNode* nextNode = temp->next;
                deleteNodes(hash , hash[sum] , temp , sum);
                temp = nextNode;
                continue;
            }
            
            temp = temp->next;
        }
        
        return newHead->next;
    }
};