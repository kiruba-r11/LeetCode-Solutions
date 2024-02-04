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
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        
        bool c1 = false;
        bool c2 = false;
        
        while(l1 && l2) {
            if(l1 == l2) return l1;
            l1 = l1->next;
            l2 = l2->next;
            
            if(!l1) {
                if(!c1) {
                    c1 = true;
                    l1 = headB;
                }
            }
            
            if(!l2) {
                if(!c2) {
                    c2 = true;
                    l2 = headA;
                }
            }
        }
        
        return NULL;
    }
};