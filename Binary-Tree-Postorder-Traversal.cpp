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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        stack<TreeNode*>sta1;
        stack<int>sta2;
        sta1.push(root);
        while(!sta1.empty()){
             TreeNode* temp=sta1.top();
             sta1.pop();
             if(temp->left!=NULL){
                sta1.push(temp->left);
             }
             if(temp->right){
                sta1.push(temp->right);
             }
             sta2.push(temp->val);
        }
        vector<int>res;
        while(!sta2.empty()){
             res.push_back(sta2.top());
             sta2.pop();
        }return res;
    }
};