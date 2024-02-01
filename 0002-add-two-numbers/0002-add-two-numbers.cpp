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
    ListNode* add(ListNode* l1 , ListNode *l2 , int carry) {
        if(!l1 && !l2) {
            if(carry != 0) {
                ListNode* newNode = new ListNode(carry);
                return newNode;
            }
            return NULL;
        }
        
        if(!l1) {
            int sum = l2->val + carry;
            int carry_ = sum / 10;
            
            sum = sum % 10;
            l2->val = sum;
            l2->next = add(l1 , l2->next , carry_);
            return l2;
        }
        
        if(!l2) {
            int sum = l1->val + carry;
            int carry_ = sum / 10;
            
            sum = sum % 10;
            l1->val = sum;
            l1->next = add(l1->next , l2 , carry_);
            return l1;
        }
        
        int sum = l1->val + l2->val + carry;
        int carry_ = sum / 10;
        
        sum = sum % 10;
        l1->val = sum;
        l1->next = add(l1->next , l2->next , carry_);
        
        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1 , l2 , 0);
    }
};