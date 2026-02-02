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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *temp=head;
        int num=0;
        while(temp!=NULL){
            temp=temp->next;
            num++;
        }
        if(k==(num-k+1))return head;
        ListNode *temp1=head;
        ListNode *temp2=head;
        int i=1;
        while(i<k){
            temp1=temp1->next;
            i++;
        }i++;
        i=1;
        while(i<(num-k+1)){
            temp2=temp2->next;
            i++;
        }
        swap(temp1->val,temp2->val);
        return dummy->next;

        
    }
};