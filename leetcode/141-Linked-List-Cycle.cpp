/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }else{
            struct ListNode *rabbit=head;
            struct ListNode *turtle=head;

            while(rabbit!=NULL && rabbit->next!=NULL){
                rabbit=rabbit->next->next;
                turtle=turtle->next;
                if(rabbit==turtle){
                    return true;
                }
            }return false;
        }
    }
};