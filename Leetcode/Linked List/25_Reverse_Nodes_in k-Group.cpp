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
    
    ListNode* reverseNodes(ListNode* head, int length, int k){
        
        if(length < k)
            return head;
        
        int count = 0;
        ListNode *curr = head, *prev = NULL, *nex = NULL;
        
        while(curr != NULL && count < k){    
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            count++;
        }
        
        if(nex != NULL){
            head->next = reverseNodes(nex,length-k,k);
        }
        
        return prev;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int length = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        
        return reverseNodes(head,length,k);
        
    }
};
