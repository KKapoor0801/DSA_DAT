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
        
        int length = 0;
        ListNode *temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        
        int mid = length/2 + 1;
        
        int i = 1;
        while(i < mid){
            head = head->next;
            i++;
        }
        
        return head;
        
    }
};
