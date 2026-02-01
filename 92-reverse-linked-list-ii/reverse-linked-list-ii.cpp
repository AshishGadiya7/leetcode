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
ListNode *reverse(ListNode *head,ListNode *pre,int n,int right){
     if(n>right||head==NULL)return pre;
     ListNode *temp=head->next;
     head->next=pre;
     pre=head;
     head=temp;
     return reverse(head,pre,n+1,right);
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode *current=head;
        int i=1;
        while(i<left){
            pre=pre->next;
            current=current->next;
            i++;
        }
        ListNode *temp1=head;
        i=1;
        while(i<=right){
            temp1=temp1->next;
            i++;
        }
        ListNode *temp=reverse(current,NULL,1,right-left+1);
        pre->next=temp;
        while(pre->next!=NULL){
            pre=pre->next;
        }
        pre->next=temp1;
        return dummy->next;
        

    }
};