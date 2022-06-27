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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || k == 0) // Corner case
            return head;
        
        ListNode *temp = head;
        int n = 0;
        while(temp->next != NULL){  // To reach the last node
            temp = temp->next;
            n++;
        }
        
        temp->next = head;
        
        int length = n+1;
        int effective_k = k % length;
        
        ListNode *temp2 = head;
        for(int i = 1 ; i < (length - effective_k) ; i++){
            temp2 = temp2->next;
        }
        
        ListNode *split = temp2->next; // the split pointer points to the node which actually becomes the end after rotation
        temp2->next = NULL;
        
        return split;
    }
};
