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
    ListNode* swapPairs(ListNode* head) {
        
        // int temp;
        // ListNode *ptr = head;
        
        ListNode *dummyNode = new ListNode();
        ListNode *prev = dummyNode, *first = head;
        prev->next = head;
        
        while(first != NULL && first->next != NULL){
            
            ListNode *second = first->next;
            ListNode *future = first->next->next;  // we can also write second->next
            
            second->next = first;
            prev->next = second;
            first->next = future;
            
            prev = first; // Moving prev and first ahead
            first = future;
        }
        
        // THIS SOLUTION IS VALID WHEN VALUES OF NODES HAVE TO BE CHANGED WITHOUT CHANGING THE POINTERS
//         while(head != NULL){
            
//             if(head->next != NULL){
//                 temp = (head->next)->val;
//                 (head->next)->val = head->val;
//                 head->val = temp;   
//             }
//             else
//                 break;
            
//             head = head->next->next;
//         }
        
//        return ptr;
          return dummyNode->next;
    }
};
