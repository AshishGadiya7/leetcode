/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* previous=NULL;
    struct ListNode* current=head;
    struct ListNode* nextnode;
    while(current!=NULL){
      
        nextnode=current->next;
        current->next=previous;
        previous=current;
        current=nextnode;
    }return previous;
    
}