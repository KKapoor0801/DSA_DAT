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
    
    ListNode* reverseLL(ListNode *head, int left, int right, int k){
        
        int count = 0;
        
        ListNode *dummyNode = new ListNode(0);
        ListNode *prev = dummyNode;
        prev->next = head;
        ListNode *temp = dummyNode->next;
        
        for(int i = 1; i < left; i++){
            temp = temp->next;
            prev = prev->next;
        }
        
        // eg - [1,2,3,4,5] , left = 2, right = 4
        // After the above for loop, temp points to 2, prev to 1
        
        ListNode *curr = temp, *pre = prev, *nex = NULL;  //nex is the variable name for next
        
        while(curr != NULL && count<k){
            nex = curr->next;
            curr->next = pre;
            
            pre = curr;
            curr = nex;
            count++;
        }
        
        prev->next = pre;  // prev was pointing at 1 only so we change the pointer for pre, i.e, 4 to prev
        temp->next = curr; // temp was pointing at 2 only so we change the pointer of 2 to the curr pointer
       
        return dummyNode->next; // dummyNode->next is done to get the starting from head
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int k = right - left + 1; 
        
        // We take k as it was a similar ques to LEETCODE 25
        
        return reverseLL(head,left,right,k);   
    }
};
