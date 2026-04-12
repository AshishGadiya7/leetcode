/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
         if(root==NULL)return res;
        queue<TreeNode*>q;
        q.push(root);
        
        int count;
        bool t=true;
        while(!q.empty()){
              count=q.size();
               vector<int>v;
              while(count>0){
                if(q.front()->right!=NULL)
                q.push(q.front()->right);
                if(q.front()->left!=NULL)
                q.push(q.front()->left);
                v.push_back(q.front()->val);
                q.pop();
                count--;
              }if(!t){
                res.push_back(v);
              }else{
                reverse(v.begin(),v.end());
                res.push_back(v);
              }
              t=!t;
        }return res;

    }
};