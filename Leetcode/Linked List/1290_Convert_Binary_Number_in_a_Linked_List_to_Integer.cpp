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
    
    ListNode* reverseList(ListNode *head){
        
        ListNode *prev = NULL, *curr = head, *nex = NULL;
        while(curr != NULL){
            nex = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    
    int getDecimalValue(ListNode* head) {
        
        int decimal = 0;
        int i = 0;
        
        ListNode *revHead = reverseList(head);
        
        while(revHead != NULL){
            decimal += (revHead->val)*((int)(pow(2,i)));
            i++;
            revHead = revHead->next;
        }
        return decimal;
    }
};
