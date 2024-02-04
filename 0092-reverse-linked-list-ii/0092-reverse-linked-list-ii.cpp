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
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        int pos = 1;
        ListNode* prev = NULL;
        while(temp) {
            if(pos == left) {
                ListNode* newhead = temp;
                ListNode* tail = NULL;
                while(temp) {
                    if(pos == right) {
                        tail = temp;
                        break;
                    }
                    pos++;
                    temp = temp->next;
                }
                
                ListNode* tailnext = tail->next;
                tail->next = NULL;
                ListNode* newhead1 = reverse(newhead);
                
                if(prev) prev->next = newhead1;
                else head = newhead1;
                newhead->next = tailnext;
                break;
            }
            pos++;
            prev = temp;
            temp = temp->next;
        }
        
        return head;
    }
};