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
int compute(TreeNode* root){
    if(root==NULL)return 0;
    int a=0,b=0;
    if(root->left!=NULL)a=compute(root->left);
    if(root->right!=NULL)b=compute(root->right);
    return max(a,b)+1;
}

bool findbalance(TreeNode* root){
    if(root==NULL)return true;
    int a=0,b=0;
    a=compute(root->left);
    b=compute(root->right);
    if(abs(a-b)>1)return false;
    return findbalance(root->left)&& findbalance(root->right);

}
    bool isBalanced(TreeNode* root) {
      return  findbalance(root);
        
    }
};