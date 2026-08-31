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
vector<int> compute(ListNode* head){
    if(head==NULL)return {-1,-1};
    int first=-1;
    int pre=head->val;
    head=head->next;
    int max_dist=INT_MIN;
    int min_dist=INT_MAX;
    int pre_point=-1;
    int temp=2;
    while(head->next!=NULL){
             if((pre<head->val && head->next->val<head->val)||(pre>head->val && head->next->val>head->val)){
                    if(pre_point!=-1){
                        min_dist=min(min_dist,temp-pre_point);
                        pre_point=temp;
                    }else{
                        pre_point=temp;
                    }

                    if(first!=-1){
                        max_dist=max(max_dist,temp-first);
                    }else{
                        first=temp;
                    }

             }temp++;
             pre=head->val;
             head=head->next;
    }
    if(min_dist==INT_MAX)min_dist=-1;
    if(max_dist==INT_MIN)max_dist=-1;
    return {min_dist,max_dist};
}
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        return compute(head);
    }
};