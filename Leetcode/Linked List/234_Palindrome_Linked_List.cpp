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
        
        // TC = O(n) and SC = O(1)
        
        ListNode* reverseList(ListNode* slow){
            
            ListNode *prev = NULL, *curr = slow, *next = NULL;
            while(curr != NULL){
                next = curr->next;
                curr->next = prev;
                
                prev = curr;
                curr = next;
            }
            return prev;
        }

    
        bool isPalindrome(ListNode* head) {
            // Find mid using 2 pointers
            ListNode *slow = head, *fast = head;
            
            while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
            
            // Optimisation to reduce the length of the list to be reversed in case we are given a list of odd length
            if(fast != NULL)
                slow = slow->next;
            
            // Reverse the linked list from mid point which is present at slow
            ListNode *revHead = reverseList(slow);
            
            // Check palindrome between starting and reversed list
            while(revHead != NULL){
                if(revHead->val != head->val)
                    return false;
                else{
                    revHead = revHead->next;
                    head = head->next;
                }
            }
            
            return true;
            
    
    // TC = SC = O(n)
    
//     bool isPalin(vector<int>& v){
        
//         int start = 0, end = v.size()-1;
        
//         while(start <= end){
//             if(v[start] != v[end])
//                 return 0;
//             else{
//                 start++;
//                 end--;
//             }
//         }
//         return 1;   
//     }
    
//     bool isPalindrome(ListNode* head) {
        
//         vector<int> v;
        
//         while(head != NULL){
//             v.push_back(head->val);
//             head = head->next;
//         }
//         return isPalin(v);
    }
};
