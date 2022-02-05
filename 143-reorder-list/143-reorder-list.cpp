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
    
    ListNode* reverse(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        // Sliding pointers approach to reverse the linked lists
        ListNode *p = NULL , *q = head , *r = head->next;
        while(r != NULL) {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        head = q;
        return head;
    }
    
    void reorderList(ListNode* head) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> 
            1. Find the middle (ceil(n / 2)) point of the list
            2. Split the list into two halves based on the middle point
            3. Reverse the second list
            4. Merge two lists alternatively
        
        */
        
        if(head->next == NULL)
            return;
        
        // Finding the mid (ceil(n / 2)) node using fast and slow pointer
        ListNode *slow = head , *fast = head->next;
        while(fast != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        // Split the linked lists into two halves based on the mid node
        ListNode *head1 = slow->next;
        slow->next = NULL;
        
        // Reverse the second half of the linked list
        head1 = reverse(head1);
        
        ListNode *temp = head , *temp1 = head1;
        
        // Merge two linked lists alternatively
        while(temp != NULL) {
            ListNode* next = temp->next;
            temp->next = temp1;
            temp = next;
            
            if(temp1)  {
                ListNode* next1 = temp1->next;
                temp1->next = temp;
                temp1 = next1;
            }
        }
        
    }
};