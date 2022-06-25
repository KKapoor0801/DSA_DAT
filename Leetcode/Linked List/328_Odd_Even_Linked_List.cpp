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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *temp = head;       
        
        // oddH = head of pointer pointing to odd nodes
        // oddT = tail of pointer pointing to odd nodes
        // Similarly for evenH and evenT
        
        ListNode *oddH = NULL, *oddT = NULL, *evenH = NULL, *evenT = NULL;
        
        int i = 1;
        while(head != NULL){
            
            if(i%2 != 0){
                if(oddH == NULL){
                    oddH = head;
                    oddT = head;
                    head = head->next;
                }
                else{
                    oddT->next = head;
                    oddT = oddT->next;
                    head = head->next;
                }
            }
            
            else if(i%2 == 0){
                if(evenH == NULL){
                    evenH = head;
                    evenT = head;
                    head = head->next;
                }
                else{
                    evenT->next = head;
                    evenT = evenT->next;
                    head = head->next;
                }
            }
            
            i++;
        }
        
        oddT->next = evenH; // Connecting odd and even linked lists
        evenT->next = NULL; // Because even tail always ends with NULL as per ques
        
        return temp; // we can also return oddH
    }
};
