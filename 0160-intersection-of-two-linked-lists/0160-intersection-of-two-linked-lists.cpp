/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        bool f1 = true , s1 = true;
        
        while(true) {
            
            if(ptr1 == ptr2) return ptr1;
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            if(!ptr1) {
                if(!f1) break;
                ptr1 = headB;
                f1 = false;
            }
            if(!ptr2) {
                if(!s1) break;
                ptr2 = headA;
                s1 = false;
            }
        }
        
        return NULL;
    }
};