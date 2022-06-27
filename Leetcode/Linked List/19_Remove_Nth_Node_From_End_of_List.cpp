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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // O(n) - single pass solution 
        
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        
        ListNode *fast = dummyNode, *slow = dummyNode;
        
        for(int i = 1 ; i<=n ; i++){
            fast = fast->next;
        }
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        
        return dummyNode->next;
        
    }
};
