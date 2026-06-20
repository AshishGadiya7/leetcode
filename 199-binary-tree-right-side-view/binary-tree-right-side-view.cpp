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
void bfs(TreeNode * root,vector<int>&res){
    queue<TreeNode*>q;
    q.push(root);
    TreeNode*  temp=q.back();
    while(!q.empty()){
        TreeNode* a=q.front();
        if(a==temp){
            res.push_back(a->val);
             if(a->left!=NULL){
            q.push(a->left);
        }
        if(a->right!=NULL){
            q.push(a->right);
        }q.pop();
        temp=q.back();
        }
        
        
        else{
        if(a->left!=NULL){
            q.push(a->left);
        }
        if(a->right!=NULL){
            q.push(a->right);
        }q.pop();}
    }
}
    vector<int> rightSideView(TreeNode* root) {

        vector<int>res;
        if(root==NULL)return res;
         bfs(root,res);
         return res;
    }
};