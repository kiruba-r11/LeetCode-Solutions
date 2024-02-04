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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessX = new ListNode(-101);
        ListNode* lptr = lessX;
        
        ListNode* moreX = new ListNode(-1);
        ListNode* mptr = moreX;
        
        ListNode* temp = head;
        while(temp) {
            if(temp->val < x) {
                lptr->next = temp;
                lptr = lptr->next;
            } else {
                mptr->next = temp;
                mptr = mptr->next;
            }
            temp = temp->next;
        }
        
        lptr->next = moreX->next;
        mptr->next = NULL;
        
        return lessX->next;
    }
};