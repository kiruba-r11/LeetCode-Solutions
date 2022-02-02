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
    
    /*
    
    [2,2,-2,1,-1,-1]
    [2,4,2,3,2,1]
    
    */
    
    void deleteNodes(map <int , ListNode*> &hash , ListNode* head , ListNode* tail , ListNode* start , int sum) {
        
        ListNode* temp = start->next;
        start->next = tail->next;
        
        // sum += temp->val;
        
        while(temp != start->next) {
            sum += temp->val;
            
            if(hash[sum] == temp)
                hash[sum] = NULL;
            tail = temp->next;
            // cout << temp->val << " ";
            // delete temp;
            temp = tail;
        }
        // cout << endl;
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        while(head && head->val == 0) {
            head = head->next;
        }
        
        if(!head) return NULL;
        
        map <int , ListNode*> hash;
        vector <int> prefix;
        
        int i = 0;
        
        // Fill prefix sum and hash map
        ListNode* temp = head , *tem = head;
        
        prefix.push_back(head->val);
        hash[prefix[i]] = temp;
        
        temp = temp->next;
        while(temp) {
            if(prefix.size())
                prefix.push_back(prefix[prefix.size() - 1] + temp->val);
            else
                prefix.push_back(temp->val);
            
            // cout << prefix.size() << endl;
            // i++;
            // cout << prefix[i] << endl;
                // cout << head->val << " " << temp->val << endl;
            if(prefix[prefix.size() - 1] == 0) {
                tem = head;
                // cout << '1' << endl;
                head = temp->next;
                // cout << '2' << endl;
                while(tem != head) {
                    temp = tem->next;
                    // cout << '3' << endl;
                    // delete tem;
                    // cout << '4' << endl;
                    tem = temp;
                    // cout << '5' << endl;
                }
                // cout << '6' << endl;
                temp = head;
                // cout << '7' << endl;
                prefix.clear();
                hash.clear();
                
            } else {
                if(hash[prefix[prefix.size() - 1]] == NULL) {
                    // cout <<prefix[prefix.size() - 1]<< endl;
                    hash[prefix[prefix.size() - 1]] = temp;
                }
                else {
                    ListNode* next = temp->next;
                    deleteNodes(hash , head , temp , hash[prefix[prefix.size() - 1]] , prefix[prefix.size() - 1]);
                    temp = next;
                    continue;
                }
                temp = temp->next;
            }
            
        }
        
        // cout << '8' << endl;
        
        return head;
    }
};