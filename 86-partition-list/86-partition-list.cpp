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
        ListNode* lh = new ListNode(-1);
        ListNode* tl = lh;
        
        ListNode* gh = new ListNode(-1);
        ListNode* tg = gh;
        
        while(head) {
            if(head->val < x) tl->next = head , tl = head , head = head->next , tl->next = NULL;
            else tg->next = head , tg = head , head = head->next , tg->next = NULL;
        }
        
        tl->next = gh->next;
        return lh->next;
    }
};