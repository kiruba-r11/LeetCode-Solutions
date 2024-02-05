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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        
        vector <ListNode*> ans(k);
        if(len / k == 0) {
            
            temp = head;
            ListNode* prev = NULL;
            int i = 0;
            while(temp) {
                ans[i++] = temp;
                k--;
                prev = temp;
                temp = temp->next;
                prev->next = NULL;
            }
        } else if(len % k == 0) {
            
            int mod = len % k;
            int tlen = len / k;
            ListNode* prev = NULL;
            temp = head;
            
            for(int i = mod; i < k; i++) {
                tlen = len / k;
                ans[i] = temp;
                while(tlen-- && temp) {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
            }
        } else {
            int mod = len % k;
            int tlen = len / k;
            ListNode* prev = NULL;
            temp = head;
            
            // 15 / 4 = 4 4 4 3 tlen + 1 for 1st mod nodes
            for(int i = 0; i < mod; i++) {
                tlen = len / k + 1;
                ans[i] = temp;
                while(tlen-- && temp) {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
            }
            
            for(int i = mod; i < k; i++) {
                tlen = len / k;
                ans[i] = temp;
                while(tlen-- && temp) {
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = NULL;
            }
        }
        
        return ans;
    }
};