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
int findheight(TreeNode* root){
    if(root==NULL)return 0;
    return max(findheight(root->left),findheight(root->right))+1;
}
void findDiameter(TreeNode *root,int &d){
    if(root==NULL)return ;
    d=max(d,findheight(root->left)+findheight(root->right));
    findDiameter(root->left,d);
    findDiameter(root->right,d);
}
    int diameterOfBinaryTree(TreeNode* root) {
           int d=0;
           findDiameter(root,d);
           return d;
    }
};