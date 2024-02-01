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
    ListNode* remove(ListNode* head , int val) {
        if(!head) return head;
        
        ListNode* removedHead = remove(head->next , val);
        if(head->val == val) return removedHead;
        head->next = removedHead;
        
        return head;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        return remove(head , val);
    }
};