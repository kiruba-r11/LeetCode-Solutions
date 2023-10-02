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
    ListNode* merge(ListNode* list1 , ListNode* list2) {
    
        if(!list1 && !list2) return NULL;
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode* head = new ListNode(-1);
        ListNode* headptr = head;
        
        ListNode* newHead = NULL;
        if(list1->val < list2->val) {
            head->next = list1;
            head = head->next;
            newHead = merge(list1->next , list2);
        } else {
            head->next = list2;
            head = head->next;
            newHead = merge(list1 , list2->next);
        }
        
        head->next = newHead;
        return headptr->next;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1 , list2);
    }
};