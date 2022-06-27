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
    ListNode* middleNode(ListNode* head) {
        
        // O(n) faster solution - SLOW (TORTOISE) AND FAST (HARE) POINTERS
        
        ListNode *slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            
            fast = fast->next->next;
            slow = slow->next;
            
        }
        
        return slow;
        
        // O(n) solution but slightly slower
        
//         int length = 0;
//         ListNode *temp = head;
//         while(temp != NULL){
//             length++;
//             temp = temp->next;
//         }
        
//         int mid = length/2 + 1;
        
//         int i = 1;
//         while(i < mid){
//             head = head->next;
//             i++;
//         }
        
//         return head;
        
    }
};
