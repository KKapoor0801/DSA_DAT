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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummyNode = new ListNode();
        ListNode *temp = dummyNode;
        temp->next = head;
        
        while(head != NULL && head->next != NULL){
            
            if(head->val == (head->next)->val){
                
                while((head != NULL && head->next != NULL) && head->val == head->next->val){
                    head = head->next;    
                }
                temp->next = head->next;
                head = head->next;
            }
            
            else{
                head = head->next;
                temp = temp->next;
            }
            
        }
        
        return dummyNode->next;
        
    }
};
