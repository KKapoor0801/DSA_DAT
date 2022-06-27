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
        
        ListNode *l2 = new ListNode(0);
        ListNode *temp = l2;
        
        ListNode *lessThan = head;
        while(lessThan != NULL){
            
            if(lessThan->val < x){
                l2->next = new ListNode(lessThan->val);
                l2 = l2->next;
            }
            lessThan = lessThan->next;
        }
        
        ListNode *greaterThan = head;
        while(greaterThan != NULL){
            
            if(greaterThan->val >= x){
                l2->next = new ListNode(greaterThan->val);
                l2 = l2->next;
            }
            
            greaterThan = greaterThan->next;
        }
        
        return temp->next;
        
        // NOTE: Can also be done in a single pass if we woud have made 2 lists for less than x and 
        // greater than x and added the elements into them in a single loop and later merged the 2 lists
    }
};
