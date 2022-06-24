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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *l3 = new ListNode(0);
        ListNode *head = l3;
        
        int carry = 0;
        
        while(l1 != NULL && l2 != NULL){
            
            int value = l1->val + l2->val + carry;
            l3 -> next = new ListNode(value % 10); // 9+7 = 16 ---> 16%10 = 6 which is value and 16/10 = 1 which is carry
            carry = value / 10;
            l1 = l1 -> next;
            l2 = l2 -> next;
            l3 = l3 -> next;
            
        }
        
        while(l1 != NULL){
            int value = l1->val + carry;
            l3 -> next = new ListNode(value % 10);
            carry = value / 10;
            l1 = l1 -> next;
            l3 = l3 -> next;
        }
        
        while(l2 != NULL){
            int value = l2->val + carry;
            l3 -> next = new ListNode(value % 10);
            carry = value / 10;
            l3 = l3 -> next;
            l2 = l2 -> next;
        }
        
        if(carry > 0){
            l3 -> next = new ListNode(carry);
        }
        
        return head -> next;
        
    }
};
