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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // METHOD 1 - 2 pointer apporach - TC = O(n) and SC = O(n)
        
        // CORNER CASES
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        if(list1 == NULL && list2 == NULL)
            return list1;
        
        // MAKING A NEW LINKED LIST TO STORE THE ANS
        ListNode *l3 = new ListNode(0);
        ListNode *temp = l3;
        
        while(list1 != NULL && list2 != NULL){
            
            if(list1->val < list2->val){
                l3->next = new ListNode(list1->val);
                list1 = list1->next;
                l3 = l3->next;
            }
            else if(list2->val < list1->val){
                l3->next = new ListNode(list2->val);
                list2 = list2->next;
                l3 = l3->next;
            }
            else{
                l3->next = new ListNode(list1->val);
                list1 = list1->next;
                l3 = l3->next;
                l3->next = new ListNode(list2->val);
                list2 = list2->next;
                l3 = l3->next;
            }
            
        }
        
        // ADDING THE REMAINING BIGGER ELEMENTS OF THE EITHER OF THE LISTS WHICH MIGHT HAVE BEEN LEFT
        
        while(list1 != NULL){
            l3->next = new ListNode(list1->val);
            list1 = list1->next;
            l3 = l3->next;
        }
        
        while(list2 != NULL){
            l3->next = new ListNode(list2->val);
            list2 = list2->next;
            l3 = l3->next;
        }
        
       return temp->next;

        
        // METHOD 2 --> Not very efficient --> TC = O(nlogn), SC = O(n) 
        
//         vector<int> v;
//         while(list1 != NULL){
//             v.push_back(list1->val);
//             list1 = list1->next;
//         }
        
//         while(list2 != NULL){
//             v.push_back(list2->val);
//             list2 = list2->next;
//         }
        
//         sort(v.begin(), v.end());
        
//         ListNode *l3 = new ListNode(0);
//         ListNode *temp = l3;
        
//         for(int i = 0 ; i<v.size() ; i++){
//             l3->next = new ListNode(v[i]);
//             l3 = l3->next;
//         }
        
//         return temp->next;          
    }
};
