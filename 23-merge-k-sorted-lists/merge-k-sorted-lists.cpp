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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<lists.size();i++){
            ListNode *temp=lists[i];
            while(temp!=NULL){
                q.push(temp->val);
                temp=temp->next;
            }
        }
        ListNode*res=new ListNode(-1);
        ListNode*dummy=res;
        while(!q.empty()){
            ListNode *temp=new ListNode(q.top());
            dummy->next=temp;
            dummy=temp;
            q.pop();
        }return res->next;
    }
};