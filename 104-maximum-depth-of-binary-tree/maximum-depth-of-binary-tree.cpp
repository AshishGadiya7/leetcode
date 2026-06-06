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
    if(root->left==NULL && root->right==NULL)return 1;
    int a=0,b=0;
    if(root->left!=NULL)a=1+compute(root->left);
    if(root->right!=NULL)b=1+compute(root->right);
    return max(a,b);
}
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        return compute(root);
    }
};